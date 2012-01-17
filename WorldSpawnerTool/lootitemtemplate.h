#ifndef LOOTITEMTEMPLATE_H
#define LOOTITEMTEMPLATE_H

extern "C" {
    #include "lua.h"
    #include "lualib.h"
    #include "lauxlib.h"
}

#include "QString"
#include "QVector"
#include "QSharedData"

class LootItemTemplate : public QSharedData{
public:
    static const int AMAZINGSUCCESS = 0;
    static const int GREATSUCCESS = 1;
    static const int GOODSUCCESS = 2;
    static const int MODERATESUCCESS = 3;
    static const int SUCCESS = 4;
    static const int MARGINALSUCCESS = 5;
    static const int OK = 6;
    static const int BARELYSUCCESSFUL = 7;
    static const int CRITICALFAILURE = 8;

public:
    LootItemTemplate(const QString& itemName);
    ~LootItemTemplate();

    void readObject(lua_State* L);

    void registerLootGroup(const QString& groupName) {
        lootGroups.append(groupName);
    }

    void unregisterLootGroup(const QString& groupName) {
        int idx = lootGroups.indexOf(groupName);

        if (idx > 0)
            lootGroups.remove(idx);
    }

    QString toString() const;

    QString serializeToLua();

    void clearAllExperimentalProperties();
    void clearAllCustomizationVariables();

    void addExperimentalProperty(const QString& property, float min, float max);
    void addCustomizationVariable(const QString& variable, quint8 min, quint8 max);

public:
    //Getters
    inline int getMinLevel() {
        return minimumLevel;
    }

    inline int getMaxLevel() {
        return maximumLevel;
    }

    inline int getQualityRangeMin() {
        return qualityRangeMin;
    }

    inline int getQualityRangeMax() {
        return qualityRangeMax;
    }

    inline QString& getCustomObjectName() {
        return customObjectName;
    }

    inline QString& getDirectObjectPath() {
        return directObjectTemplate;
    }

    inline QString& getDraftSchematic() {
        return draftSchematic;
    }

    inline QString& getItemName() {
        return itemTemplate;
    }

    inline QVector<QString> getLootGroups() {
        return lootGroups;
    }

    inline QString getExperimentalPropertyAt(int idx) {
        return experimentalSubGroupTitles.at(idx);
    }

    inline float getExperimentalMinAt(int idx) {
        return experimentalMin.at(idx);
    }

    inline float getExperimentalMaxAt(int idx) {
        return experimentalMax.at(idx);
    }

    inline int getTotalExperimentalProps() {
        return experimentalSubGroupTitles.count();
    }

    inline QString getCustomizationVarAt(int idx) {
        return customizationStringNames.at(idx);
    }

    inline quint8 getCustomizationMinAt(int idx) {
        return customizationValueMin.at(idx);
    }

    inline quint8 getCustomizationMaxAt(int idx) {
        return customizationValueMax.at(idx);
    }

    inline int getTotalCustomizationVars() {
        return customizationStringNames.count();
    }

    //Setters
    inline void setItemName(const QString& name) {
        itemTemplate = name;
    }

    inline void setCustomObjectName(const QString& name) {
        customObjectName = name;
    }

    inline void setDraftSchematic(const QString& name) {
        draftSchematic = name;
    }

    inline void setDirectObjectPath(const QString& name) {
        directObjectTemplate = name;
    }

    inline void setMaxLevel(int lvl) {
        maximumLevel = lvl;
    }

    inline void setMinLevel(int lvl) {
        minimumLevel = lvl;
    }

private:
    QString itemTemplate;

    int minimumLevel;
    int maximumLevel;

    QString customObjectName;
    QString directObjectTemplate;
    QString draftSchematic;

    QVector<QString> experimentalSubGroupTitles;
    QVector<float> experimentalMin;
    QVector<float> experimentalMax;

    int qualityRangeMin;
    int qualityRangeMax;

    QVector<QString> customizationStringNames;
    QVector<quint8> customizationValueMin;
    QVector<quint8> customizationValueMax;

    //This is a vector of all the loot groups this template is a part of. This makes lookup faster for removal.
    QVector<QString> lootGroups;
};

#endif // LOOTITEMTEMPLATE_H
