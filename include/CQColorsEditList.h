#ifndef CQColorsEditList_H
#define CQColorsEditList_H

#include <QFrame>

class CQColorsTheme;
class CQColorEdit;

class QComboBox;
class QListWidget;
class QListWidgetItem;

/*!
 * \brief Widget to control themes and associated lists of palettes
 */
class CQColorsEditList : public QFrame {
  Q_OBJECT

  Q_PROPERTY(QString themeName READ themeName WRITE setThemeName)

 public:
  CQColorsEditList(QWidget *parent=nullptr);

  const QString &themeName() const { return themeName_; }
  void setThemeName(const QString &name);

 public slots:
  void updateThemes();
  void updateLists();
  void updateData();

 private:
  void connectSlots(bool connect);

  bool getCurrentItem(QListWidgetItem* &item, int &row) const;

  bool getAllItem(QListWidgetItem* &item, int &row) const;

  CQColorsTheme *currentTheme() const;

 signals:
  void palettesChanged();

 private slots:
  void themesComboSlot(int);

  void upTopSlot();
  void upSlot   (bool top=false);
  void downSlot ();
  void leftSlot ();
  void rightSlot();

  void selectColorSlot(const QColor &c);
  void insideColorSlot(const QColor &c);

 private:
  QString      themeName_;
  QComboBox*   themesCombo_     { nullptr }; //!< theme combo box
  QListWidget* currentList_     { nullptr }; //!< theme current palettes list
  QListWidget* allList_         { nullptr }; //!< theme unused palettes list
  CQColorEdit* selectColorEdit_ { nullptr }; //!< theme select color edit
  CQColorEdit* insideColorEdit_ { nullptr }; //!< theme inside color edit
};

#endif
