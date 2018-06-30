// Check off a specific todos by clicking
$("ul").on("click", "li", function(){
	$(this).toggleClass("completed");
});


// Click on X to delete todo (without bubbling)
$("ul").on("click", "span",  function(event){
	$(this).parent().fadeOut(500, function(){
		$(this).remove();
	});
	event.stopPropagation(); // stops from executing script for parent elements
});


// Create a new todo
$("input[type='text']").keypress(function(event){
	if(event.which === 13) //check for enter key press
	{
		var todoText = $(this).val();
		$(this).val("");
		$("ul").append("<li><span><i class='fas fa-trash-alt'></i></span> " + todoText + "</li>");

	}
});


$("#addLogo").click(function(){
	$("input[type='text']").fadeToggle();
});
