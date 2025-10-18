#pragma once
#include <QObject>
#include <QString>

#include <QFileDialog>

class FileSearcher : public QObject
{
	Q_OBJECT

  private:
	QString currentFilePath;

	bool removeAppDir();

  public:
	explicit FileSearcher(QObject* parent = nullptr);
	~FileSearcher() = default;

  public slots:
	bool saveFile(QString& text);
	bool saveFileAs(QString& newFilePath, QString& text);

  signals:
};
