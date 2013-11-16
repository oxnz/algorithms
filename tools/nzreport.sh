#!/bin/sh
# Version: @VERSION@
# Author: Oxnz <yunxinyi@gmail.com>
# This file is part of the @PACKAGE@ project
# Copyright (C) 2013 Oxnz <yunxinyi@gmail.com>, All rights reserved

report="report.html"
ofile="chart.js"

# truncate file
if [ -e $report ]; then
	: > $report
fi
if [ -e $ofile ]; then
	: > $ofile
fi

cat >> $report << HTMLEND
<html>
  <head>
  	<!-- THIS FILE IS GENERATED BY RDREPORT.SH, DO NOT EDIT THIS FILE BY HAND
	-->
	  <script src="DRAWJS" type="text/javascript"></script>
  </head>
  <body onLoad="onload()">
    <div id="banner">
      <h1>NZLab</h1>
      <hr />
    </div>
    <div id="content">
        <canvas id="chart"
                height="400" width="960" style="border:1px solid #000000;">
          Your borwser does not support canvas
        </canvas>
    </div>
    <div id="footer">
    </div>
  </body>
</html>
HTMLEND

sed -i -e "s/DRAWJS/$ofile/" $report

cat >> $ofile << DRAWCHART

/*
	THIS FILE IS GENERATED BY NZREPORT.SH, DO NOT EDIT THIS FILE BY HAND
*/

function onload() {
	show();
}

function line(x) {
	return 3*x + 1;
}

function draw(ctx, f, x0, x1, nx, y0, y1, ny, title) {
	h = 400;
	w = 960;
	ctx.fillStyle = '#FFFFFF';
	ctx.fillRect(0, 0, w, h);
	var dx = w/nx;
	var dy = h/ny;
	/* draw coordinate */
	ctx.fillStyle = '#000000';
	ctx.font = '10px Arial';
	ctx.moveTo(0, h/2);
	ctx.lineTo(w, h/2);
	ctx.stroke();
	ctx.moveTo(w/2, 0);
	ctx.lineTo(w/2, h);
	ctx.stroke();
	ctx.strokeStyle = 'FF0000';
	for (var i = 0; i < nx; ++i) {
		ctx.moveTo(i*dx, h/2-4);
		ctx.lineTo(i*dx, h/2);
		ctx.stroke();
		ctx.fillText(x0 + (x1-x0)/nx*i, i*dx-10, h/2+12);
		for (var j = 0; j < 1; j += 0.05) {
			ctx.moveTo((i-j)*dx-1, h/2-f(x0+(x1-x0)/nx*(i-j))*ny/(y1-y0)*dy);
			ctx.lineTo((i-j)*dx+1, h/2-f(x0+(x1-x0)/nx*(i-j))*ny/(y1-y0)*dy);
			ctx.stroke();
		}
	}
	for (var i = 0; i < ny; ++i) {
		ctx.moveTo(w/2+4, i*dy);
		ctx.lineTo(w/2, i*dy);
		ctx.stroke();
		ctx.fillText(-(y0 + (y1-y0)/ny*i), w/2+10, i*dy);
	}
	ctx.fillStyle = '#FF0000';
	ctx.font = '24px Arial';
	ctx.fillText(title, w/2-80, h);
}

function show(d) {
	draw(
			ctx = document.getElementById('chart').getContext('2d'),
			f = line,
			x0 = -40,
			x1 = 40,
			nx = 40,
			y0 = -40,
			y1 = 40,
			ny = 20,
			title = "f(x) = 3*x + 1"
			);
}

