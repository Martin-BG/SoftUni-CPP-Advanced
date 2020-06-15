#include <algorithm>
#include "Snake.h"

Snake::Snake(const int fieldRows, const int fieldCols, const Point& startPos) :
    _FIELD_ROWS(fieldRows),
    _FIELD_COLS(fieldCols),
    _currPos(startPos),
    _snakeNodes{ startPos } { }

Snake::~Snake() { }

StatusCode Snake::move(Direction dir,
                       const std::vector<Point>& obstacles,
                       std::vector<Point>& powerUps) {

  Point newPos = _currPos;

  switch (dir) {
  case Direction::UP:
    --newPos.row;
    break;
  case Direction::DOWN:
    ++newPos.row;
    break;
  case Direction::LEFT:
    --newPos.col;
    break;
  case Direction::RIGHT:
    ++newPos.col;
    break;
  }

  if (newPos.row < 0 || newPos.row >= _FIELD_ROWS ||
      newPos.col < 0 || newPos.col >= _FIELD_COLS ||
      std::find(obstacles.cbegin(), obstacles.cend(), newPos) != obstacles.cend() ||
      std::find(_snakeNodes.cbegin(), _snakeNodes.cend(), newPos) != _snakeNodes.cend()) {
    return StatusCode::SNAKE_DEAD;
  }

  _currPos = newPos;
  _snakeNodes.emplace_front(newPos);

  const auto& powerUp = std::find(powerUps.cbegin(), powerUps.cend(), _currPos);
  if (powerUp != powerUps.cend()) {
    powerUps.erase(powerUp);
    return StatusCode::SNAKE_GROWING;
  }

  _snakeNodes.pop_back();
  return StatusCode::SNAKE_MOVING;
}

std::deque<Point>& Snake::getSnakeNodes() {
  return _snakeNodes;
}
