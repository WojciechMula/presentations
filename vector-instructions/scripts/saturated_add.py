#!/usr/bin/env python3
import sys
from PIL import Image

GRAYSCALE = 'L'


def main():
    source = Image.open(sys.argv[1])
    shift = 127
    try:
        shift = int(sys.argv[2]) & 0xff
    except (IndexError, ValueError):
        pass
    
    wrap = convert(source, lambda x: (x + shift) & 0xff)
    wrap.save("cat_add_wrap.png")
    
    sat = convert(source, lambda x: min(x + shift, 255))
    sat.save("cat_add_sat.png")


def convert(image, function):
    assert image.mode == GRAYSCALE

    result = Image.new(image.mode, (image.width, image.height))

    dst = result.getdata()
    for x in range(image.width):
        for y in range(image.height):
            pixel = (x, y)
            dst.putpixel(pixel, function(image.getpixel(pixel)))

    return result


if __name__ == '__main__':
    main()
