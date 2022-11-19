#ifndef MALOM_BOARD_H
#define MALOM_BOARD_H

#include <QWidget>


class Board : public QWidget {
	Q_OBJECT

	static constexpr double circle_ratio_outer  = 0.8;
	static constexpr double circle_ratio_middle = 0.55;
	static constexpr double circle_ratio_inner  = 0.3;

	static constexpr double table_dot_ratio  = 0.015;
	
	static constexpr size_t node_count = 24;
	static constexpr size_t connection_count = 32;
	
	using Nodes = std::array<QPoint, node_count>;
	using Connections = std::array<std::pair<int, int>, connection_count>;

public:
	explicit Board(QWidget* parent = nullptr);
	virtual ~Board() override = default;

	void paintEvent(QPaintEvent*) override;
	
	QSize sizeHint() const override;
	QSize minimumSizeHint() const override;
	
private:
	void calculateTableNodePositions();
	int calculateDotSize() const;
	
	static const Connections buildConnections();
	
	Nodes nodes;

	static const Connections connections;
};


#endif // MALOM_BOARD_H
