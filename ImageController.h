#ifndef IMAGECONTROLLER_H
#define IMAGECONTROLLER_H

#include <QObject>
#include <QUrl>

class ImageController : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QUrl imageSource READ imageSource WRITE setImageSource NOTIFY imageSourceChanged)
public:
    explicit ImageController(QObject *parent = nullptr);

    Q_INVOKABLE QUrl imageSource() const;
    Q_INVOKABLE void setImageSource(const QUrl &newImageSource);
    Q_INVOKABLE void loadImage();
    Q_INVOKABLE void saveImage(const QUrl &imageSource);

signals:

    void imageSourceChanged();

private:
    QUrl m_imageSource;
};

#endif // IMAGECONTROLLER_H
