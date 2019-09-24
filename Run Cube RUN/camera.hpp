#ifndef CAMERA
#define CAMERA

class Camera {
public:
  Camera();
  ~Camera();

  void step();

  void move(int x, int y);
  int getX() { return x;}
  int getY() { return y;}
  int getScrollSpeed() { return scrollSpeed; }
  void GoFaster() { scrollSpeed += 1; }
  void Reset() { scrollSpeed = 4; }

private:
  float x;
  float y;
  float scrollSpeed;
};

#endif
