#!/usr/bin/perl

#@list = (3,6,7,1,5,9,8,2,4);
@list = (43,34,5,65675,47,7,87,64,4,365,467,78,6,865,856,3,45,23);

for($i  =1; $i < @list; $i++){
	print "round $i\n";
	$temp = $list[$i];
	print "temp is $temp\n";
	$j = $i;
	print "previous number is $list[$j-1]\n............\n";
	while($j > 0 && $list[$j-1] > $temp){
		$list[$j] = $list[$j-1];
		print "j is $j\n";
		$j--;
	}
	print "............";
	$list[$j] = $temp;

	print "\n\n";
}

foreach $x(@list){
	print "$x ";
}

print "\n";
