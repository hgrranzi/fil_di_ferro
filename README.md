# fil_di_ferro

School 21 project<br>
Basics of graphic programming

## Status

IN PROGRESS

## Description

This project is about creating a simplified graphic wireframe representation of a relief landscape linking various points via segments. The coordinates of this landscape are stored in a file passed as
a parameter.<br>

![file](./test_maps/file_example.png)

Each number in the file corresponds to a point in space:

<ul>
  <li>The horizontal position corresponds to its axis</li>
  <li>The vertical position corresponds to its ordinate</li>
  <li>The first value corresponds to its altitude</li>
  <li>The second value (if exists) corresponds to its color</li>
</ul>

## Installation

	git clone --recurse-submodules https://github.com/hgrranzi/fil_di_ferro.git

For Mac OS:

	git checkout main
	make

For Linux:

	make

## Getting started

	./fil_di_ferro [path to the config file with the fdf extention]

Example:

	./fil_di_ferro test_maps/europe.fdf

## Preview

Keyboard control

<ul>
  <li><b>0</b>:      color mode</li>
  <li><b>+</b>:      zoom +</li>
  <li><b>-</b>:      zoom -</li>
  <li><b>w</b>:      ...</li>
  <li><b>s</b>:      ...</li>
  <li><b>a</b>:      ...</li>
  <li><b>d</b>:      ...</li>
</ul>
