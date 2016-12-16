#!/usr/bin/perl
#
use strict;

#my @list  = (3, 6, 5, 1, 7, 4, 9, 2, 8);

my @list;
while(1){
	print "Number in list, \"end\" to end\n";
	my $num = <STDIN>;
	chomp($num);
	if($num =~ /end/i){
		last;
	}elsif($num !~ /\d+/){
		print "Number please\n";
		next;
	}else{
		push(@list, $num);
	}	
}

#print "@list\n";
our @listin = @list;

sub quicksort($$){
	my ($l, $r) = @_;
	if($l < $r){
		my ($i, $j, $mark) = ($l, $r, $listin[$l]);
		while($i < $j){
			while($i < $j && $listin[$j] >= $mark){
				$j--;
			}
			if($i < $j){
				$listin[$i++] = $listin[$j];
			}
			while($i < $j && $listin[$i] <= $mark){
				$i++;
			}
			if($i < $j){
				$listin[$j--] = $listin[$i];
			}
		}
		$listin[$i] = $mark;
		my $position = $i;
		print "$i\n@listin\n";
		&quicksort($l, $i-1);
		&quicksort($i+1, $r);
	}	
	return @listin;
}

my ($low, $high) = (0, @list-1);

&quicksort($low, $high);
