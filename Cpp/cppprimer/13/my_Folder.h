#include <set>
using std::set;

#include <string>
using std::string;

#include <utility>

class Folder;

/*****************************************************/
/************* class Message declaration *************/
/*****************************************************/

class Message {
private:
    string content;
    set<Folder *> folders;
    void add_to_folders(const Message& msg);
    void remove_from_folders();
    void move_folders(Message *m);

public:
    Message(const string &s = "") : content(s){};
    Message(const Message &msg);
    Message(Message &&msg) noexcept;
    ~Message();
    Message &operator=(const Message &msg);
    Message &operator=(Message &&msg) noexcept;
    void save(Folder &f);
    void remove(Folder &f);
    void addFldr(Folder *f) { folders.insert(f); }
    void remFldr(Folder *f) { folders.erase(f); }
};

/****************************************************/
/************* class Folder declaration *************/
/****************************************************/

class Folder {
private:
    set<Message *> msgs;
    void add_to_messages(const Folder &f);
    void remove_from_messages();

public:
    Folder() = default;
    Folder(const Folder &f);
    ~Folder();
    Folder &operator=(const Folder &f);
    void addMsg(Message *m) { msgs.insert(m); }
    void remMsg(Message *m) { msgs.erase(m); }
};

/****************************************************/
/************* class Message definition *************/
/****************************************************/

void Message::save(Folder &f){
    f.addMsg(this);
    addFldr(&f);
}

void Message::remove(Folder &f){
    f.remMsg(this);
    remFldr(&f);
}

void Message::add_to_folders(const Message& msg){
    for (auto &pf : msg.folders)
        pf->addMsg(this);
}

Message::Message(const Message &msg): content(msg.content), folders(msg.folders){
    add_to_folders(msg);
}

void Message::move_folders(Message *m) {
    for (auto& pf:folders){
        pf->remMsg(m);
        pf->addMsg(this);
    }
    m->folders.clear();
}

Message::Message(Message &&msg) noexcept: content(std::move(msg.content)), folders(std::move(msg.folders)){
    move_folders(&msg);
}

void Message::remove_from_folders(){
    for (auto& pf:folders)
        pf->remMsg(this);
}

Message::~Message(){
    remove_from_folders();
}

Message& Message::operator=(const Message &msg){
    remove_from_folders();
    content = msg.content;
    folders = msg.folders;
    add_to_folders(msg);
    return *this;
}

Message& Message::operator=(Message &&msg) noexcept{
    if (this != &msg){
        remove_from_folders();
        content = std::move(msg.content);
        folders = std::move(msg.folders);
        move_folders(&msg);
    }
    return *this;
}

/***************************************************/
/************* class Folder definition *************/
/***************************************************/
void Folder::add_to_messages(const Folder &f){
    for (auto &pm : f.msgs)
        pm->addFldr(this);
}

Folder::Folder(const Folder &f) : msgs(f.msgs) {
    add_to_messages(f);
}

void Folder::remove_from_messages(){
    for (auto &pm : msgs)
        pm->remFldr(this);
}

Folder::~Folder() {
    remove_from_messages();
}

Folder& Folder::operator=(const Folder &f){
    remove_from_messages();
    msgs = f.msgs;
    add_to_messages(f);
    return *this;
}
