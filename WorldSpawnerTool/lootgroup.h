#ifndef LOOTGROUP_H_
#define LOOTGROUP_H_

extern "C" {
    #include "lua.h"
    #include "lualib.h"
    #include "lauxlib.h"
}

#include "QMap"
#include "QString"
#include "QSharedData"

class LootGroup : public QSharedData {
public:
    static const int EXPECTED_SUM = 10000000; // 10,000,000

public:
    LootGroup(const QString& name);
    virtual ~LootGroup();

    void readObject(lua_State* L);
    QString serializeToLua();

    void normalizeWeights();

    void addLootItemTemplate(const QString& templateName, int chance);
    void removeLootItemTemplate(const QString& templateName);

    QString toString() const;

public:
    //Getters
    inline int getMinimumLevel() {
        return minimumLevel;
    }

    inline int getMaximumLevel() {
        return maximumLevel;
    }

    inline QString& getGroupName() {
        return groupName;
    }

    inline int getChance(const QString& templateName) {
        return entries.value(templateName, 0);
    }

    inline QString& getDescription() {
        return description;
    }

    inline QMap<QString, int> getEntriesCopy() {
        return entries;
    }

    inline bool hasLootItemTemplate(const QString& itemName) {
        return entries.contains(itemName);
    }

    //Setters
    inline void setMinimumLevel(int lvl) {
        minimumLevel = lvl;
    }

    inline void setMaximumLevel(int lvl) {
        maximumLevel = lvl;
    }

    inline void setGroupName(const QString& name) {
        groupName = name;
    }

    inline void setDescription(const QString& desc) {
        description = desc;
    }

    inline void setChance(const QString& templateName, int weight) {
        if (entries.contains(templateName)) {
            entries[templateName] = weight;
        }
    }

private:
    QMap<QString, int> entries;

    int minimumLevel;
    int maximumLevel;

    QString groupName;
    QString description;
};

#endif /* LOOTGROUP_H_ */
