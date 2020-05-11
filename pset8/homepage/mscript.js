function validateForm() {
var x = document.forms["myForm"]["fname"].value;
var y = document.forms["myForm"]["femail"].value;
if (y == "" || x == "") {
    window.alert("Check for correct input on submission");
}
else {
    window.alert("Thank you for submmiting your contact!"); 
}
}