#include "Searcher.h"

namespace searcher {
    list<MatrixNode> Searcher::getNeighbors(Problem problem, MatrixNode node) {
        list<MatrixNode> neighbors;
        //GET LEFT NEIGHBOR
        if (node.getPosition().getCol() != 0) {
            int row = node.getPosition().getRow(), col = node.getPosition().getCol() - 1;
            Position po(row, col);
            double key = po.getHashKey();
            int nodeValue = problem.getMatrix().find(key)->second.getValue();
            if (nodeValue != -1) {
                auto *m1 = new MatrixNode(
                        problem.getMatrix().find(Position(row, col).getHashKey())->second.getPosition(),
                        problem.getMatrix().find(Position(row, col).getHashKey())->second.getValue());
                neighbors.push_back(*m1);
            }
        }
        //GET RIGHT NEIGHBOR
        if (node.getPosition().getCol() + 1 != problem.getSize()) {
            int row = node.getPosition().getRow(), col = node.getPosition().getCol() + 1;
            Position po(row, col);
            double key = po.getHashKey();
            int nodeValue = problem.getMatrix().find(key)->second.getValue();
            if (nodeValue != -1) {
                auto *m1 = new MatrixNode(
                        problem.getMatrix().find(Position(row, col).getHashKey())->second.getPosition(),
                        problem.getMatrix().find(Position(row, col).getHashKey())->second.getValue());
                neighbors.push_back(*m1);
            }
        }
        //GET TOP NEIGHBOR
        if (node.getPosition().getRow() != 0) {
            int row = node.getPosition().getRow() - 1, col = node.getPosition().getCol();
            Position po(row, col);
            double key = po.getHashKey();
            int nodeValue = problem.getMatrix().find(key)->second.getValue();
            if (nodeValue != -1) {
                auto *m1 = new MatrixNode(
                        problem.getMatrix().find(Position(row, col).getHashKey())->second.getPosition(),
                        problem.getMatrix().find(Position(row, col).getHashKey())->second.getValue());
                neighbors.push_back(*m1);
            }
        }
        //GET BOTTOM NEIGHBOR
        if (node.getPosition().getRow() + 1 != problem.getSize()) {
            int row = node.getPosition().getRow() + 1, col = node.getPosition().getCol();
            Position po(row, col);
            double key = po.getHashKey();
            int nodeValue = problem.getMatrix().find(key)->second.getValue();
            if (nodeValue != -1) {
                auto *m1 = new MatrixNode(
                        problem.getMatrix().find(Position(row, col).getHashKey())->second.getPosition(),
                        problem.getMatrix().find(Position(row, col).getHashKey())->second.getValue());
                neighbors.push_back(*m1);
            }
        }

        return neighbors;
    }

    void Searcher::insertOpen(SearcherState &state,queue<SearcherState>&open) {
        open.push(state);
        queue<SearcherState> tempQ;
        while (!open.empty()) {
            auto *minState = new SearcherState(open.front().getCost(), *(open.front().getNode()),
                                               *(open.front().getParent()));
            open.pop();
            for (int i = 0; i < (int) open.size(); i++) {
                if (open.front().getCost() < minState->getCost()) {
                    open.push(*minState);
                    minState = new SearcherState(open.front().getCost(), *(open.front().getNode()),
                                                 *(open.front().getParent()));
                    open.pop();
                } else {
                    open.push(open.front());
                    open.pop();
                }
            }
            tempQ.push(*minState);
        }
        int size = tempQ.size();
        for (int i = 0; i < size; i++) {
            open.push(tempQ.front());
            tempQ.pop();
        }
    }

    bool Searcher::isUnmarked(MatrixNode &newState,list<MatrixNode>marked) {
        for (auto &marked_state : marked) {
            if (newState == marked_state) {
                return false;
            }
        }
        return true;
    }

    bool Searcher::inOpen(MatrixNode &m,queue<SearcherState>open) {
        int size = open.size();
        bool in = false;
        for (int i = 0; i < size; i++) {
            if (m == *(open.front().getNode())) {
                in = true;
            }
            open.push(open.front());
            open.pop();
        }
        return in;
    }

    bool Searcher::inClosed(MatrixNode &m,queue<SearcherState>close) {
        int size = close.size();
        bool in = false;
        for (int i = 0; i < size; i++) {
            if (m == *(close.front().getNode())) {
                in = true;
            }
            close.push(close.front());
            close.pop();
        }
        return in;
    }
} // namespace searcher