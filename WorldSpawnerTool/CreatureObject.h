#ifndef CREATUREOBJECT_H
#define CREATUREOBJECT_H

#include <QString>
#include <QVector>
#include <QMap>
#include <QTextStream>

extern "C" {
#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"
}

class CreatureObject {
    QString fileName;
    QString luaObjectName;
    QString objectName;
    QString pvpFaction;
    QString faction;
    QString socialGroup;
    int level;
    float chanceHit;
    int damageMin;
    int damageMax;
    int baseXp;
    int baseHAM;
    int baseHAMmax;
    int armor;
    int pvpBitmask;

    QVector<float> resists;

    QString meatType;
    int meatAmount;
    QString hideType;
    int hideAmount;
    QString boneType;
    int boneAmount;

    int milk;
    float tamingChance;
    int ferocity;

    QVector<QString> templates;
    int creatureBitmask;
    int diet;
    int optionsBitmask;

    QVector<QString> lootGroups;
    QVector<QString> weapons;
    QMap<QString, QString> attacks;
    QString conversationTemplate;

public:
    CreatureObject(const QString& objectName);

    CreatureObject() {
    }

    const static int AGGRESSIVE = 2;
    const static int ATTACKABLE = 1;
    const static int ENEMY = 0x20;
    const static int OVERT = 4;

    const static int PACK = 1;
    const static int HERD = 2;
    const static int KILLER = 4;
    const static int STALKER = 8;
    const static int BABY = 16;
    const static int LAIR = 0x20;
    const static int HEALER = 0x40;

    const static int HERBIVORE = 2;
    const static int CARNIVORE = 1;

    void readObject(lua_State* l);

    void setVariable(const QString& name, const QString& data);

    QString serializeToLua();

    void addPvpBitmaskVariableToText(QTextStream& stream, const QString& varName);
    void addCreatureBitmaskVariableToText(QTextStream& stream, const QString& varName);
    void addDietBitmaskVariableToText(QTextStream& stream, const QString& varName);
    void attacksVariableToText(QTextStream& stream, const QString& varName);

    void parsePvpBitmask(const QString& data);
    void parseDiet(const QString& data);
    void parseCreatureBitmask(const QString& data);
    void parseStringVector(QVector<QString>& vector, const QString& data);
    void parseAttacks(const QString& data);
    void parseResists(const QString& data);

    void setOptionsBitmaskBit(int bit, bool value);

//    void saveCurrentCreature();

    inline QString getStringFromData(const QString& data) {
        return data.mid(1, data.length() - 2);
    }

    inline QString& getLuaObjectName() {
        return luaObjectName;
    }

    inline void setObjectName(const QString& n) {
        objectName = n;
    }

    inline void setPvpFaction(const QString& fac) {
        pvpFaction = fac;
    }

    inline void setSocialGroup(const QString& con) {
        socialGroup = con;
    }

    inline void setArmor(int a) {
        armor = a;
    }

    inline void setBaseHAM(int v) {
        baseHAM = v;
    }

    inline void setBaseHAMmax(int v) {
        baseHAMmax = v;
    }

    inline void setLevel(int v) {
        level = v;
    }

    inline void setBaseXp(int v) {
        baseXp = v;
    }

    inline void setMinDamage(int v) {
        damageMin = v;
    }

    inline void setMaxDamage(int v) {
        damageMax = v;
    }

    inline void setChanceHit(float v) {
        chanceHit = v;
    }

    inline void setPvpBitmask(int v) {
        pvpBitmask = v;
    }

    inline void setOptionsBitmask(int mask) {
        optionsBitmask = mask;
    }

    inline void setFileName(const QString& file) {
        fileName = file;
    }

    inline void setCreatureBitmask(int v) {
        creatureBitmask = v;
    }

    inline void setConversationTemplate(const QString& templ) {
        conversationTemplate = templ;
    }

    inline void setMilk(int v) {
        milk = v;
    }

    inline void setFerocity(int v) {
        ferocity = v;
    }

    inline void setTamingChance(float tam) {
        tamingChance = tam;
    }

    inline void setDietBitmask(int v) {
        diet = v;
    }

    inline void setResists(const QVector<float>& res) {
        resists = res;
    }

    inline void setAttacks(const QMap<QString, QString>& a) {
        attacks = a;
    }

    inline void setTemplates(const QVector<QString>& s) {
        templates = s;
    }

    inline void setLootGroups(const QVector<QString>& s) {
        lootGroups = s;
    }

    inline void setWeapons(const QVector<QString>& s) {
        weapons = s;
    }

    inline void setBoneType(const QString& t) {
        boneType = t;
    }

    inline void setBoneAmount(int a) {
        boneAmount = a;
    }

    inline void setHideType(const QString& type) {
        hideType = type;
    }

    inline void setHideAmount(int v) {
        hideAmount = v;
    }

    inline void setMeatType(const QString& a) {
        meatType = a;
    }

    inline void setMeatAmount(int a) {
        meatAmount = a;
    }

    inline QString& getObjectName() {
        return objectName;
    }

    inline QString& getPvpFaction() {
        return pvpFaction;
    }

    inline QString& getSocialGroup() {
        return socialGroup;
    }

    inline int getArmor() {
        return armor;
    }

    inline int getBaseHAM() {
        return baseHAM;
    }

    inline int getBaseHAMmax() {
        return baseHAMmax;
    }

    inline int getLevel() {
        return level;
    }

    inline int getBaseXp() {
        return baseXp;
    }

    inline int getMinDamage() {
        return damageMin;
    }

    inline int getMaxDamage() {
        return damageMax;
    }

    inline float getChanceHit() {
        return chanceHit;
    }

    inline QString& getFileName() {
        return fileName;
    }

    inline bool hasPvpFlag(int flag) {
        return pvpBitmask & flag;
    }

    inline int getMilk() {
        return milk;
    }

    inline int getOptionsBitmask() {
        return optionsBitmask;
    }

    inline QString getConverstationTemplate() {
        return conversationTemplate;
    }

    inline int getFerocity() {
        return ferocity;
    }

    inline float getTamingChance() {
        return tamingChance;
    }

    inline bool hasCreatureFlag(int flag) {
        return creatureBitmask & flag;
    }

    inline bool hasDietFlag(int flag) {
        return diet & flag;
    }

    inline QVector<float>* getResists() {
        return &resists;
    }

    inline QVector<QString>* getTemplates() {
        return &templates;
    }

    inline QVector<QString>* getWeapons() {
        return &weapons;
    }

    inline QVector<QString>* getLootGroups() {
        return &lootGroups;
    }

    inline QMap<QString, QString>* getAttacks() {
        return &attacks;
    }

    inline QString& getMeatType() {
        return meatType;
    }

    inline int getMeatAmount() {
        return meatAmount;
    }

    inline QString& getHideType() {
        return hideType;
    }

    inline int getHideAmount() {
        return hideAmount;
    }

    inline QString& getBoneType() {
        return boneType;
    }

    inline int getBoneAmount() {
        return boneAmount;
    }

};

#endif // CREATUREOBJECT_H
