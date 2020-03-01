var person = {
    name: "Tom",
    age: 18,
    printInfo: function (state) {
        console.log("name: " + this.name + " age: " + this.age + " state: " + state)
    },
}

person.printInfo("good");

console.log(typeof document);
console.log(typeof Date());
document.getElementById("img1").src = "hello.jpg";
document.getElementById("img1").style.width = "350px";
document.getElementById("img1").style.height = "200px";
// document.getElementById("text1").onmouseover = function () {
//     document.getElementById("text1").style.color = "red";
// };
// document.getElementById("text1").onmouseout = function () {
//     document.getElementById("text1").style.color = "lightcoral";
// };
console.log(document.getElementsByTagName("p"));

$(function () {
    $("#text1").attr("style", "color: green");
});

// $("#text1").mouseenter(function(){
//     $(this).attr("style", "color: red");
// })
// $("#text1").mouseleave(function(){
//     $(this).attr("style", "color: lightcoral");
// })

$("#text1").hover(function(){
    $(this).attr("style", "color: red");
}, function(){
    $(this).attr("style", "color: lightcoral");
})

$("#btn1").click(function() {
    $("#data1").load("data_test.txt", function(responseTxt, statusTxt, xhr) {
        if (statusTxt == "success")
            $(this).html(responseTxt);
        else if (statusTxt == "error")
            alert("error: " + xhr.status + " " + xhr.statusText)
    });
});
