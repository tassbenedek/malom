#include "board.h"
#include <QPainter>


Board::Board(QWidget* parent) 
	: QWidget(parent)
{}

void Board::paintEvent(QPaintEvent*) {
	calculateTableNodePositions();
	const auto dot_size = calculateDotSize();
	
	QPainter painter(this);
	painter.setBrush(Qt::black);
	painter.setPen(QPen(Qt::black, dot_size / 3 + 1));
	
	for (const auto& conn : connections)
		painter.drawLine(nodes[conn.first], nodes[conn.second]);
	
	painter.setPen(Qt::darkCyan);
	
	for (const auto& node : nodes)
		painter.drawEllipse(node, dot_size, dot_size);

}

QSize Board::sizeHint() const {
    return QSize(500, 500);
}

QSize Board::minimumSizeHint() const {
    return QSize(200, 200);
}

void Board::calculateTableNodePositions() {
	const auto w = width();
	const auto h = height();

	const QPoint center {w / 2, h / 2};
	const int half_dist = std::min(w, h) / 2;
	
	const int hd_outer  = half_dist *circle_ratio_outer;
	const int hd_middle = half_dist *circle_ratio_middle;
	const int hd_inner  = half_dist *circle_ratio_inner;
	
	nodes = Nodes{
		// outer circle
		center + QPoint{-hd_outer, -hd_outer},
		center + QPoint{-hd_outer,         0},
		center + QPoint{-hd_outer,  hd_outer},
		center + QPoint{        0,  hd_outer},
		center + QPoint{ hd_outer,  hd_outer},
		center + QPoint{ hd_outer,         0},
		center + QPoint{ hd_outer, -hd_outer},
		center + QPoint{        0, -hd_outer},
		
		// middle circle
		center + QPoint{-hd_middle, -hd_middle},
		center + QPoint{-hd_middle,          0},
		center + QPoint{-hd_middle,  hd_middle},
		center + QPoint{         0,  hd_middle},
		center + QPoint{ hd_middle,  hd_middle},
		center + QPoint{ hd_middle,          0},
		center + QPoint{ hd_middle, -hd_middle},
		center + QPoint{         0, -hd_middle},
		
		// inner circle
		center + QPoint{-hd_inner, -hd_inner},
		center + QPoint{-hd_inner,         0},
		center + QPoint{-hd_inner,  hd_inner},
		center + QPoint{        0,  hd_inner},
		center + QPoint{ hd_inner,  hd_inner},
		center + QPoint{ hd_inner,         0},
		center + QPoint{ hd_inner, -hd_inner},
		center + QPoint{        0, -hd_inner}
	};
}

int Board::calculateDotSize() const {
	return std::min(width(), height()) * table_dot_ratio;
}

const Board::Connections Board::buildConnections() {
	Connections ret;

	for (int i = 0; i < 24; ++i) ret[i] = {i, i + 1};
	ret[7] = {7, 0};
	ret[15] = {15, 8};
	ret[23] = {23, 16};

	const std::array<std::pair<int, int>, 8> cross_lines {{
		{ 1,  9}, { 9, 17},
		{ 3, 11}, {11, 19},
		{ 5, 13}, {13, 21},
		{ 7, 15}, {15, 23}
	}};

	for (int i = 0; i < 8; ++i) ret[i + 24] = cross_lines[i];

	return ret;
}

const Board::Connections Board::connections = 
	Board::buildConnections();
