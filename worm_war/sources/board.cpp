#include "board.h"
#include <thread>
#include <mutex>

Board::Board(int width, int height) : nextId_{1}, killAll_{false} {
    if (height <= 0 || width <= 0 ) {
        throw std::invalid_argument("Incorrect height or width value.");
    }
  board_.resize(height);
  for (int i = 0; i < (int)board_.size(); ++i)
        board_[i].resize(width);
}

void Board::addWorm(WormType type, int x, int y) {
  // TODO: Implement the body of the function. It should add a worm
  // into the board_ and start a new thread which will invoke
  // call operator - operator()(int) - defined in Worm class.
  // Note: there are a few class members (like wormTypes_) that need to be
  // updated as well to have full information about the worm that is being
  // added. They are usually based on worm's id which should be uniquely given
  // here.
    wormTypes_ [nextId_] = type;
    board_[x][y] = nextId_;
    if (type == Lazy) {
        worms_[nextId_] = std::thread(LazyWorm(x,y,this),nextId_);
    } else {
        worms_[nextId_] = std::thread(HunterWorm(x,y,this),nextId_);
    };
    ++nextId_;
}

void Board::update(int id, int oldX, int oldY, int newX, int newY) {
    std::unique_lock<std::mutex> locker(mtx);
    if (this->checkKill(id)) {
        return;
    }
  int targetId = board_[newX][newY];
  if (targetId != 0 && targetId != id)
    killed_.insert(targetId);
  board_[oldX][oldY] = 0;
  board_[newX][newY] = id;
}

bool Board::checkKill(int id) {
  return killAll_ || killed_.find(id) != killed_.end();
}

void Board::killAll() {
  killAll_ = true;
}

Board::~Board() {
    killAll();
    for(auto &worm : worms_)
        worm.second.join();
}

void Board::clearDead() {
  for (int i = 0; i < (int)board_.size(); ++i)
    for (int j = 0; j < (int)board_[0].size(); ++j)
      if (killed_.find(board_[i][j]) != killed_.end())
        board_[i][j] = 0;
}
