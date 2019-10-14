{
if (substr($1, 1, 1) == "#") #checks for "#"
	{
	print "Colums are in this order: \n"substr($1, 2)"\n"; #substr to remove the "#"
	}
else
	{
	print; # if no "#" is in front just print it
	}
} 
END{print "end of file";}
