#ifndef PICTURE_H
#define PICTURE_H

#include <string>
#include <vector>

#include "lodepng.h"

struct rgbColor {
  int r = 255;
  int g = 255;
  int b = 255;
};

class Picture {
public:
  /**
     Constructs a picture with width and height zero.
  */
  Picture();

  /**
     Constructs a picture from the given PNG file.
     @param filename a file name that should specify a PNG file.
  */
  Picture(std::string filename);

  /**
     Constructs a picture with pixels in a single color (by default,
     white).
     @param red the red value of the pixels (between 0 and 255)
     @param green the green value of the pixels (between 0 and 255)
     @param blue the blue value of the pixels (between 0 and 255)
     @param width the width of the picture
     @param height the height of the picture
  */
  Picture(int width, int height, rgbColor color);

  /**
     Constructs a picture from a two-dimensional std::vector of gray levels.
     @param grays the gray levels
  */
  Picture(const std::vector<std::vector<int>> &grays);

  /**
     Returns the width of this picture.
     @return the width
  */
  int width() const { return _width; }

  /**
     Returns the height of this picture.
     @return the height
  */
  int height() const { return _height; }

  /**
     Saves this picture to the given file.
     @param filename a file name that should specify a PNG file.
  */
  void save(std::string filename) const;

  /**
     Yields the red value at the given position.
     @param x the x-coordinate (column)
     @param y the y-coordinate (row)
     @return the red value of the pixel (between 0 and 255),
     or 0 if the given point is not in the picture.
  */
  int red(int x, int y) const;

  /**
     Yields the green value at the given position.
     @param x the x-coordinate (column)
     @param y the y-coordinate (row)
     @return the green value of the pixel (between 0 and 255),
     or 0 if the given point is not in the picture.
  */
  int green(int x, int y) const;

  /**
     Yields the blue value at the given position.
     @param x the x-coordinate (column)
     @param y the y-coordinate (row)
     @return the blue value of the pixel (between 0 and 255),
     or 0 if the given point is not in the picture.
  */
  int blue(int x, int y) const;

  /**
     Sets a pixel to a given color, expanding
     the picture if necessary.
     @param x the x-coordinate (column)
     @param y the y-coordinate (row)
     @param red the red value of the pixel (between 0 and 255)
     @param green the green value of the pixel (between 0 and 255)
     @param blue the blue value of the pixel (between 0 and 255)
  */
  void set(int x, int y, rgbColor color);

  /**
     Yields the gray levels of all pixels of this image.
     @return a 2D array of gray values (between 0 and 255)
  */
  std::vector<std::vector<int>> grays() const;

  /**
     Adds a picture to this picture at a given position, expanding
     the picture if necessary.
     @param other the picture to add
     @param x the x-coordinate (column) of the top left corner
     @param y the y-coordinate (row) of the top left corner
  */
  void add(const Picture &other, int x = 0, int y = 0);

  void scale(const size_t factor);

private:
  void ensure(int x, int y);

  std::vector<unsigned char> _values;
  int _width;
  int _height;
};

#endif
