#include "core/filesearcher.hpp"
#include <QStandardPaths>
#include <QDebug>

namespace
{
	QString appName = "Noter";

	QString getDocumentsPath()
	{
		return QStandardPaths::writableLocation(QStandardPaths::StandardLocation::DocumentsLocation);
	}

	QString getAppDirPath()
	{
		return getDocumentsPath() + "/" + appName;
	}

}; // namespace

FileSearcher::FileSearcher(QObject* parent) : QObject(parent), currentFilePath(getAppDirPath())
{
	qDebug() << "Current path: " << currentFilePath;
}

bool FileSearcher::saveFile(QString& text)
{
	if (currentFilePath.isEmpty())
	{
		return false;
	}

	QFile fileToSave(currentFilePath);
	if (!fileToSave.open(QIODeviceBase::WriteOnly | QIODevice::Text))
	{
		return false;
	}

	QTextStream outputToFile(&fileToSave);
	outputToFile << text;

	fileToSave.close();

	return true;
}

bool FileSearcher::saveFileAs(QString& newFilePath, QString& text)
{
	currentFilePath = newFilePath;
	if (!saveFile(text))
	{
		return false;
	}

	return true;
}

bool FileSearcher::removeAppDir()
{
	QString appDirPath = getAppDirPath();
	QDir appDir(appDirPath);

	if (!appDir.exists())
	{
		qDebug() << "Delete" << appDirPath << ": Fail / No such directory exists";
		return false;
	}

	if (!appDir.removeRecursively())
	{
		qDebug() << "Delete" << appDirPath << ": Fail / Can't delete directory or its content";
		return false;
	}

	qDebug() << "Remove" << appDirPath << ": Success";
	return true;
}