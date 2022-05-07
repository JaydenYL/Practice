
document.addEventListener("DOMContentLoaded", function(){

	var sum = 0;
	var list = document.getElementsByTagName("li");

	for (i = 0; i < list.length; i++){
		sum += parseInt(list[i].innerHTML);
	}
	alert(sum)
	

//	var listItems = document.getElementsByTagName("li");
//	for (var i = 0; i < listItems.length; i++)
//		{
//			sum += parseInt(listItems[i].innerHTML);
//		}
//
//	sum = 0;
//	for (var i = 0; i < listItems.length; i++)
//		{
//			var cVal = listItems[i].innerHTML;
//			sum += parseInt(cVal);
//			listItems[i].innerHTML = cVal + "(" + sum + ")";
//		}
//
	var sumTag = document.createTextNode("The sum is: " + sum);
	document.body.appendChild( sumTag );
//
//	alert("hello world")

});