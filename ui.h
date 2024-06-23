#pragma once

#include "service.h"
#include "MyTableModel.h"

#include <QMainWindow>
#include <QWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QTableWidget>
#include <QTableView>
#include <QLineEdit>
#include <QPushButton>
#include <QFormLayout>
#include <QPaintEvent>
#include <QMessageBox>
#include <QPainter>
#include <QPen>
#include <QDebug>

#include <utility>

class Painter : public QWidget {
private:
	map<string, int> genuri;
public:
	explicit Painter(map<string, int> genuri) : genuri(genuri) {
		this->repaint();
	}
	void paintEvent(QPaintEvent* ev) override;
};

class AppGUI : public QWidget {
public:
	AppGUI(Service& service) : srv(service) {
		initGUI();
		loadTable(srv.getMelodii(), srv.frecvente_autor(), srv.frecvente_gen());
		connectSignals();
		this->repaint();
	}
public:
	Service& srv;
	MyTableModel* model = nullptr;
	QTableView* tabel = new QTableView;

	QPushButton* btn_adauga = new QPushButton{ "&Adauga" };
	QPushButton* btn_sterge = new QPushButton{ "&Sterge" };
	QLineEdit* txt_titlu = new QLineEdit;
	QLineEdit* txt_artist = new QLineEdit;
	QLineEdit* txt_gen = new QLineEdit;

	void initGUI();
	void loadTable(const vector<Melodie>& melodii, const map<string, int> autori, const map<string, int> genuri);
	void connectSignals();
	void paintEvent(QPaintEvent* ev) override;
};


