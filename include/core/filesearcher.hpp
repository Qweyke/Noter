#pragma once

#include <QFileDialog>

class FileSearcher : public QWidget
{
	Q_OBJECT

  public:
	explicit FileSearcher(QWidget* parent = nullptr);
	~FileSearcher();
};
