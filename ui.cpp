#include "ui.h"

void AppGUI::initGUI() {
	QHBoxLayout* mainLayout = new QHBoxLayout;
	setLayout(mainLayout);

	mainLayout->addSpacing(30);
	QVBoxLayout* st = new QVBoxLayout;
	mainLayout->addLayout(st);
	st->addSpacing(20);

	QLabel* tabelLabel = new QLabel("Tabel melodii");
	tabelLabel->setAlignment(Qt::AlignCenter);
	st->addWidget(tabelLabel);

	tabel->resizeColumnsToContents();
	tabel->setMinimumSize(610, 350);
	st->addWidget(tabel, 2);
	st->addSpacing(20);
	
	QVBoxLayout* dr = new QVBoxLayout;
	mainLayout->addLayout(dr);
	dr->addSpacing(20);

	QFormLayout* formLayout = new QFormLayout;
	dr->addLayout(formLayout);

	formLayout->addRow(new QLabel{ "Titlu: " }, txt_titlu);
	formLayout->addRow(new QLabel{ "Artist: " }, txt_artist);
	formLayout->addRow(new QLabel{ "Gen: " }, txt_gen);
	formLayout->addWidget(btn_adauga);

	dr->addWidget(btn_sterge);
	dr->addSpacing(20);
	mainLayout->addSpacing(30);
}

void AppGUI::loadTable(const vector<Melodie>& melodii, const map<string, int> autori, const map<string, int> genuri) {
	model = new MyTableModel{ melodii, autori, genuri };
	tabel->setSelectionMode(QAbstractItemView::SingleSelection);
	tabel->setModel(model);
}

void AppGUI::connectSignals() {
	QObject::connect(btn_adauga, &QPushButton::clicked, [this] {
		auto titlu = txt_titlu->text().toStdString();
		auto artist = txt_artist->text().toStdString();
		auto gen = txt_gen->text().toStdString();

		qDebug() << titlu << "  " << artist << " " << gen << '\n';

		QMessageBox msg;
		try {
			srv.adauga(titlu, artist, gen);
			repaint();
		}
		catch (RepoException& mesaj) {
			QMessageBox::warning(this, "Warning", QString::fromStdString(mesaj.get_mesaj()));
		}
		catch (ValidatorException& mesaj) {
			QMessageBox::warning(this, "Warning", QString::fromStdString(mesaj.get_mesaj()));
		}

		txt_titlu->clear();
		txt_artist->clear();
		txt_gen->clear();
		loadTable(srv.getMelodii(), srv.frecvente_autor(), srv.frecvente_gen());
		});

	QObject::connect(btn_sterge, &QPushButton::clicked, [this] {
		if (tabel->selectionModel()->selectedIndexes().isEmpty()) {
			return;
		}
		auto row = tabel->selectionModel()->selectedIndexes().at(0).row();
		auto id = tabel->model()->data(tabel->model()->index(row, 0), Qt::DisplayRole).toInt();
		try {
			srv.sterge(id);
			repaint();
		}
		catch (RepoException& mesaj) {
			QMessageBox::warning(this, "Warning", QString::fromStdString(mesaj.get_mesaj()));
		}

		loadTable(srv.getMelodii(), srv.frecvente_autor(), srv.frecvente_gen());
		});
}

void Painter::paintEvent(QPaintEvent* ev) {

}

void AppGUI::paintEvent(QPaintEvent* ev) {
	QPainter p{ this };
	p.setPen(Qt::darkRed);
	int pop = 0, rock = 0, folk = 0, disco = 0;
	
	for (const auto& m : srv.getMelodii()) {
		if (m.getGen() == "pop") {
			pop++;
			p.drawEllipse(QPoint(0, 0), pop * 8, pop * 8);
		}
		if (m.getGen() == "rock") {
			rock++;
			p.drawEllipse(QPoint(p.device()->width(), 0), rock * 8, rock * 8);
		}
		if (m.getGen() == "folk") {
			folk++;
			p.drawEllipse(QPoint(0, p.device()->height()), folk * 8, folk * 8);
		}
		if (m.getGen() == "disco") {
			disco++;
			p.drawEllipse(QPoint(p.device()->width(), p.device()->height()), disco * 8, disco * 8);
		}
	}
}
