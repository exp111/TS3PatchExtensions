#pragma once

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply.h>
#include <QDir>
#include <QFile>
#include <map>
using namespace std;

class QtDownloader : public QObject
{
	Q_OBJECT

private:
	QNetworkAccessManager * manager;
	map<QUrl, QString> pathMap;

public:
	QtDownloader(QObject* parent = nullptr) {};
	~QtDownloader() {};

	void doDownload(QString url, QString filePath)
	{
		manager = new QNetworkAccessManager(this);

		connect(manager, SIGNAL(finished(QNetworkReply*)),
			this, SLOT(replyFinished(QNetworkReply*)));

		QUrl qurl = QUrl(url);
		this->pathMap[qurl] = filePath;
		manager->get(QNetworkRequest(qurl));
		printf("Started Download from %s\n", url.toStdString().c_str());
	}

public slots:
	void replyFinished(QNetworkReply* reply)
	{
		if (reply->error())
		{
			printf("Error: %s\n", reply->errorString().toStdString().c_str());
		}
		else
		{
			QString dir = this->pathMap[reply->url()];
			QFile* file = new QFile(dir);
			if (file->open(QFile::WriteOnly))
			{
				file->write(reply->readAll());
				file->flush();
				file->close();
				printf("Successfully downloaded file to %s\n", dir.toStdString().c_str());
			}
			else
			{
				printf("Couldn't open file %s\n", dir.toStdString().c_str());
			}
			delete file;

			reply->deleteLater();
		}
	}
};
