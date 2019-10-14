BEGIN {ctr=0;} #counter to know when 30 lines passed
{
if (substr($1, 1, 1) == "#")
	{
	head=substr($1, 2)
	header();
	}
else
	{
	ctr++;
	if (ctr % 30 == 0)
		header();
	print;
	} 
}
END{print "end of file";}

function header(){
	print("\nColums are in this order: \n" head "\n");
}
