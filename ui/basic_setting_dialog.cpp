#include "basic_setting_dialog.hpp"
#include "ui_basic_setting_dialog.h"

#include <QSettings>
#include <QVariant>

basic_setting_dialog::basic_setting_dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::basic_setting_dialog)
{
    ui->setupUi(this);

    check_box_settings_.emplace_back("img_type/bmp_checked", ui->cb_bmp);
    check_box_settings_.emplace_back("img_type/jpeg_checked", ui->cb_jpeg);
    check_box_settings_.emplace_back("img_type/pbm_checked", ui->cb_pbm);
    check_box_settings_.emplace_back("img_type/pgm_checked", ui->cb_pgm);
    check_box_settings_.emplace_back("img_type/png_checked", ui->cb_png);
    check_box_settings_.emplace_back("img_type/ppm_checked", ui->cb_ppm);
    check_box_settings_.emplace_back("img_type/tiff_checked", ui->cb_tiff);
    check_box_settings_.emplace_back("img_type/webp_checked", ui->cb_webp);
    check_box_settings_.emplace_back("Search/perfect_match", ui->cb_perfect_match);
    check_box_settings_.emplace_back("App/auto_update", ui->cb_auto_update);

    QSettings const settings(tr("freedom"), tr("similar_vision"));
    for(auto &pair : check_box_settings_){
        if(settings.contains(pair.first)){
            pair.second->setChecked(settings.value(pair.first).toBool());
        }
    }
}

basic_setting_dialog::~basic_setting_dialog()
{
    QSettings settings(tr("freedom"), tr("similar_vision"));
    for(auto &pair : check_box_settings_){
        settings.setValue(pair.first, pair.second->isChecked());
    }
    settings.setValue("version", 1.0);

    delete ui;
}

bool basic_setting_dialog::auto_update() const
{
    return ui->cb_auto_update->isChecked();
}

bool basic_setting_dialog::perfect_match() const
{
    return ui->cb_perfect_match->isChecked();
}

QStringList basic_setting_dialog::scan_img_type() const
{
    QStringList types;
    std::vector<std::pair<QString, QCheckBox*>> const mapper
    {
        {"bmp", ui->cb_bmp}, {"jpeg", ui->cb_jpeg},
        {"jpg", ui->cb_jpeg},{"pbm", ui->cb_pbm},
        {"pgm", ui->cb_pgm}, {"png", ui->cb_png},
        {"ppm", ui->cb_ppm}, {"tiff", ui->cb_tiff},
        {"webp", ui->cb_webp}
    };
    for(auto const &pair : mapper){
        if(pair.second->isChecked()){
            types.push_back(pair.first);            
        }
    }

    return types;
}