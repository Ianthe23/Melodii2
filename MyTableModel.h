#pragma once

#include <QAbstractTableModel>
#include <QAbstractItemView>
#include <map>
#include <vector>

#include "domain.h"

using std::vector;
using std::map;

class MyTableModel :public QAbstractTableModel {
	vector<Melodie> melodii;
	map<string, int> autori;
	map<string, int> genuri;
public:
	MyTableModel(const vector<Melodie>& melodii, const map<string, int> autori, const map<string, int> genuri) {
		this->melodii = melodii;
		this->autori = autori;
		this->genuri = genuri;
	}

	int rowCount(const QModelIndex& parent = QModelIndex{}) const override {
		return melodii.size();
	}

	int columnCount(const QModelIndex& parent = QModelIndex{}) const override {
		return 6;
	}

	QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override {
		if (role == Qt::DisplayRole) {
			const Melodie& m = melodii[index.row()];
			switch (index.column()) {
			case 0:
				return QString::number(m.getId());
			case 1:
				return QString::fromStdString(m.getTitlu());
			case 2:
				return QString::fromStdString(m.getArtist());
			case 3:
				return QString::fromStdString(m.getGen());
			case 4:
				return QString::number(autori.at(m.getArtist()));
			case 5:
				return QString::number(genuri.at(m.getGen()));
			}
		}
		return QVariant();
	}

	QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override {
		if (role == Qt::DisplayRole && orientation == Qt::Horizontal) {
			switch (section) {
			case 0:
				return "ID";
			case 1:
				return "Titlu";
			case 2:
				return "Artist";
			case 3:
				return "Gen";
			case 4:
				return "Cu acelasi autor";
			case 5:
				return "Cu acelasi gen";
			default:
				return QString("");
			}
		}
		return QVariant();
	}

	void setMelodii(const vector<Melodie> melodii, map<string, int> autori, map<string, int> genuri) {
		this->melodii = melodii;
		this->autori = autori;
		this->genuri = genuri;

		auto topLeft = createIndex(0, 0);
		auto bottomRight = createIndex(rowCount(), columnCount());
		emit layoutChanged();
		emit dataChanged(topLeft, bottomRight);
	}
};