#!/usr/bin/env perl -w
# 
# ===============================================================
#
# Filename:	TestRegex.pl
#
# Author:		Oxnz
# Email:		yunxinyi@gmail.com
# Created:		[2015-11-17 12:47:30 CST]
# Last-update:	2015-11-17 12:47:30 CST
# Description: ANCHOR
#
# Version:		0.0.1
# Revision:	[None]
# Revision history:	[None]
# Date Author Remarks:	[None]
#
# License:
# Copyright (c) 2013 Oxnz
#
# Distributed under terms of the [LICENSE] license.
# [license]
#
# ===============================================================
#

use strict;
use warnings;

use Stream qw/show/;
use Regex qw/concat union literal/;

my $z = concat(union(literal("a"), literal("b")),
	union(literal("c"), literal("d")));
show($z);
