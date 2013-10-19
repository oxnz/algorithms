#!/usr/bin/env perl

use strict;
use warnings;
use integer;

my ($word, $file) = @ARGV
open (FILE, $file) or die "Can't open $file: $!";
my $position = binary_search_file(\*FILE, $word);

if (defined $position) { print "$word occurs at position $position\n" }
else				   { print "$word does not occur in $file.\n" }

sub binary_search_file {
	my ( $file, $word ) = @_;
	my ( $high, $low, $mid, $mid2, $line );
	$low = 0;	# Guaranteed to be the start of a line.
        # stat returns a 13-element list giving the status info for a file:
        # ($dev, $ino, $mode, $nlink, $uid, $gid, $rdev, $size, $atime,
        # $mtime, $ctime, $blksize, $blocks) = stat($filename);
	$high = (stat($file))[7];	# Might not be the start of a line.
        # \W match a non-"word" character
	$word =~ s/\W//g;	# Remove puncuation from $word.
	$word = lc($word);	# Convert $word to lower case.

	while ($high != $low) {
		$mid = ($high+$low)/2;
		seek($file, $mid, 0) || die "Couldn't seek : $!\n";

		# $mid is probably in the middle of a line, so read the
                # rest and set $mid2 to that new position.
		$line = <$file>
		$mid2 = tell($file);

		if ($mid2 < $high) { # We're not near file's end, so read on.
			$mid = $mid2;
			$line = <$file>;
		} else { # $mid plunked us in the last line, so linear search.
			seek($file, $low, 0) || die "Couldn't seek: $!\n";
			while ( defined( $line = <$file> ) ) {
				last if compare( $line, $word ) >= 0;
				$low = tell($file);
			}
			last;
		}

		if (compare($line, $word) < 0) { $low = $mid }
		else { $high = $mid }
	}

	return if compare( $line, $word );
	return $low;
}

sub compare { # $word1 needs to be lowercased; $word2 doesn't.
	my ($word1, $word2) = @_;
	$word1 =~ s/\W//g; $word1 = lc($word1);
	return $word1 cmp $word2;
}
