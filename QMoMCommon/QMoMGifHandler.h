#ifndef QGIFLIBHANDLER_H
#define QGIFLIBHANDLER_H

#include <QImageIOHandler>
#include <QImage>
#include <QVariant>

#include <QMoMSharedPointers.h>

class QMoMGifHandler : public QImageIOHandler
{
public:
    QMoMGifHandler();
	bool canRead () const;
	bool read ( QImage * image );
    bool readAnimation(QMoMAnimation& animation);
    bool write ( const QImage & image );
	static bool canRead(QIODevice *device);
	bool supportsOption ( ImageOption option ) const;
	void setOption ( ImageOption option, const QVariant & value );
	QVariant option( ImageOption option ) const;

private:
//	QVariant m_description;
	QString m_description;
};

#endif // QGIFLIBHANDLER_H
