from field import StringField, IntegerField
from metamodel import Model

class User(Model):
    # 定义类的属性到列的映射：
    id = IntegerField('id')
    name = StringField('username')
    email = StringField('email')
    password = StringField('password')

if __name__ == "__main__":
    # 创建一个实例：
    u = User(id=12345, name='Michael', email='test@orm.org', password='my-pwd')
    # 保存到数据库：
    u.save()
