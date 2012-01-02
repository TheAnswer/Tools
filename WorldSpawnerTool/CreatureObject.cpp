#include "CreatureObject.h"
#include "creatureluamanager.h"
#include "LuaSerializerHelper.h"
#include "mainwindow.h"

CreatureObject::CreatureObject(const QString& objectName) {
  this->luaObjectName = objectName;

  level = 0;
  chanceHit = 0;
  damageMin = 0;
  damageMax = 0;
  baseXp = 0;
  baseHAM = 0;
  baseHAMmax = 0;
  armor = 0;
  pvpBitmask = 0;

  for (int i = 0; i < 9; ++i)
    resists.append(-1);

  meatAmount = 0;

  hideAmount = 0;

  boneAmount = 0;

  milk = 0;
  tamingChance = 0;
  ferocity = 0;

  creatureBitmask = 0;
  diet = 0;
  optionsBitmask = 0;
}

void CreatureObject::readObject(lua_State* l) {
  meatType = CreatureLuaManager::getStringField(l, "meatType");
  boneType = CreatureLuaManager::getStringField(l, "boneType");
  hideType = CreatureLuaManager::getStringField(l, "hideType");
  objectName = CreatureLuaManager::getStringField(l, "objectName");
  socialGroup = CreatureLuaManager::getStringField(l, "socialGroup");
  faction = CreatureLuaManager::getStringField(l, "faction");
  level = CreatureLuaManager::getIntField(l, "level");
  chanceHit = CreatureLuaManager::getFloatField(l, "chanceHit");
  damageMin = CreatureLuaManager::getIntField(l, "damageMin");
  damageMax = CreatureLuaManager::getIntField(l, "damageMax");
  //range = LuaManager::getIntField(l, "range");
  baseXp = CreatureLuaManager::getIntField(l, "baseXp");
  baseHAM = CreatureLuaManager::getIntField(l, "baseHAM");
  baseHAMmax = CreatureLuaManager::getIntField(l, "baseHAMmax");
  armor = CreatureLuaManager::getIntField(l, "armor");
  meatType = CreatureLuaManager::getStringField(l, "meatType");
  meatAmount = CreatureLuaManager::getIntField(l, "meatAmount");
  hideType = CreatureLuaManager::getStringField(l, "hideType");
  hideAmount = CreatureLuaManager::getIntField(l, "hideAmount");
  boneType = CreatureLuaManager::getStringField(l, "boneType");
  boneAmount = CreatureLuaManager::getIntField(l, "boneAmount");
  milk = CreatureLuaManager::getIntField(l, "milk");
  tamingChance = CreatureLuaManager::getFloatField(l, "tamingChance");
  ferocity = CreatureLuaManager::getIntField(l, "ferocity");
  pvpBitmask = CreatureLuaManager::getIntField(l, "pvpBitmask");
  creatureBitmask = CreatureLuaManager::getIntField(l, "creatureBitmask");
  diet = CreatureLuaManager::getIntField(l, "diet");
  conversationTemplate = CreatureLuaManager::getStringField(l, "conversationTemplate");
  optionsBitmask = CreatureLuaManager::getIntField(l, "optionsBitmask");
  pvpFaction = CreatureLuaManager::getStringField(l, "pvpFaction");

  //LuaObject res = templateData->getObjectField("resists");
  lua_pushstring(l, "resists");
  lua_gettable(l, -2);


  resists.clear();

  int resTableSize = luaL_getn(l, -1);

  if (resTableSize == 9) {
    for (int i = 1; i < 10; ++i) {

      lua_rawgeti(l, -1, i);
      float result = (float)lua_tonumber(l, -1);
      lua_pop(l, 1);

      resists.append(result);
    }


  }

  lua_pop(l, 1);


  //LuaObject temps = templateData->getObjectField("templates");
  lua_pushstring(l, "templates");
  lua_gettable(l, -2);

  templates.clear();;

  int templatesTableSize = luaL_getn(l, -1);

  for (int i = 1; i <= templatesTableSize; ++i) {
    lua_rawgeti(l, -1, i);
    const char* result = lua_tostring(l, -1);

    templates.append(QString(result));

    lua_pop(l, 1);
  }

  lua_pop(l, 1);


  //LuaObject loots = templateData->getObjectField("lootgroups");
  lua_pushstring(l, "lootgroups");
  lua_gettable(l, -2);

  int lootgroupsTableSize = luaL_getn(l, -1);

  lootGroups.clear();

  for (int i = 1; i <= lootgroupsTableSize; ++i) {
    lua_rawgeti(l, -1, i);
    const char* result = lua_tostring(l, -1);
    lua_pop(l, 1);
    lootGroups.append(QString(result));
  }

  lua_pop(l, 1);

  lua_pushstring(l, "weapons");
  lua_gettable(l, -2);

  int weaponsTableSize = luaL_getn(l, -1);

  weapons.clear();

  for (int i = 1; i <= weaponsTableSize; ++i) {
    lua_rawgeti(l, -1, i);
    const char* result = lua_tostring(l, -1);
    lua_pop(l, 1);
    weapons.append(QString(result));
  }

  lua_pop(l, 1);

  //LuaObject attackList = templateData->getObjectField("attacks");

  lua_pushstring(l, "attacks");
  lua_gettable(l, -2);


  int attackListSize = luaL_getn(l, -1);

  //lua_State* L = attackList.getLuaState();
  for (int i = 1; i <= attackListSize; ++i) {
    lua_rawgeti(l, -1, i);
    //LuaObject atk(L);

    //if (atk.isValidTable()) {
    int atkSize = luaL_getn(l, -1);

    if (atkSize == 2) {
      //String com = atk.getStringAt(1);
      lua_rawgeti(l, -1, 1);
      QString com = lua_tostring(l, -1);
      lua_pop(l, 1);
      //QString c


      //String arg = atk.getStringAt(2);

      lua_rawgeti(l, -1, 2);
      QString arg = lua_tostring(l, -1);
      lua_pop(l, 1);

      attacks[com] = arg;
      //attacks->addAttack(com, arg);
    }
    //}

    //atk.pop();
    lua_pop(l, 1);
  }

  lua_pop(l, 1);


  // attackList.pop();
}

void CreatureObject::setOptionsBitmaskBit(int bit, bool value) {
  if (value) {
    if (!(bit & optionsBitmask))
      optionsBitmask |= bit;
  } else {
    if (bit & optionsBitmask)
      optionsBitmask &= ~bit;
  }
}

QString CreatureObject::serializeToLua() {
  QString data;
  QTextStream stream(&data);

  stream << luaObjectName << " = Creature:new {" << endl;

  LuaSerializerHelper::addStringVariableToText(stream, "objectName", objectName);
  stream << "," << endl;

  LuaSerializerHelper::addStringVariableToText(stream, "socialGroup", socialGroup);
  stream << "," << endl;

  LuaSerializerHelper::addStringVariableToText(stream, "pvpFaction", pvpFaction);
  stream << "," << endl;

  LuaSerializerHelper::addStringVariableToText(stream, "faction", faction);
  stream << "," << endl;

  LuaSerializerHelper::addIntVariableToText(stream, "level", level);
  stream << "," << endl;

  LuaSerializerHelper::addFloatVariableToText(stream, "chanceHit", chanceHit);;
  stream << "," << endl;

  LuaSerializerHelper::addIntVariableToText(stream, "damageMin", damageMin);
  stream << "," << endl;

  LuaSerializerHelper::addIntVariableToText(stream, "damageMax", damageMax);
  stream << "," << endl;

  LuaSerializerHelper::addIntVariableToText(stream, "baseXp", baseXp);
  stream << "," << endl;

  LuaSerializerHelper::addIntVariableToText(stream, "baseHAM", baseHAM);
  stream << "," << endl;

  LuaSerializerHelper::addIntVariableToText(stream, "baseHAMmax", baseHAMmax);
  stream << "," << endl;

  LuaSerializerHelper::addIntVariableToText(stream, "armor", armor);
  stream << "," << endl;

  LuaSerializerHelper::addVectorToText(stream, "resists", resists);
  stream << "," << endl;

  LuaSerializerHelper::addStringVariableToText(stream, "meatType", meatType);
  stream << "," << endl;

  LuaSerializerHelper::addIntVariableToText(stream, "meatAmount", meatAmount);
  stream << "," << endl;

  LuaSerializerHelper::addStringVariableToText(stream, "hideType", hideType);
  stream << "," << endl;

  LuaSerializerHelper::addIntVariableToText(stream, "hideAmount", hideAmount);
  stream << "," << endl;

  LuaSerializerHelper::addStringVariableToText(stream, "boneType", boneType);
  stream << "," << endl;

  LuaSerializerHelper::addIntVariableToText(stream, "boneAmount", boneAmount);
  stream << "," << endl;

  LuaSerializerHelper::addIntVariableToText(stream, "milk", milk);
  stream << "," << endl;

  LuaSerializerHelper::addFloatVariableToText(stream, "tamingChance", tamingChance);
  stream << "," << endl;

  LuaSerializerHelper::addIntVariableToText(stream, "ferocity", ferocity);
  stream << "," << endl;

  addPvpBitmaskVariableToText(stream, "pvpBitmask");
  stream << "," << endl;

  addCreatureBitmaskVariableToText(stream, "creatureBitmask");
  stream << "," << endl;

  LuaSerializerHelper::addIntVariableToText(stream, "optionsBitmask", optionsBitmask);
  stream << "," << endl;

  addDietBitmaskVariableToText(stream, "diet");
  stream << "," << endl << endl;

  LuaSerializerHelper::addStringVectorToText(stream, "templates", templates);
  stream << "," << endl;

  LuaSerializerHelper::addStringVectorToText(stream, "lootgroups", lootGroups);
  stream << "," << endl;

  LuaSerializerHelper::addStringVectorToText(stream, "weapons", weapons);
  stream << "," << endl;

  LuaSerializerHelper::addStringVariableToText(stream, "conversationTemplate", conversationTemplate);
  stream << "," << endl;

  attacksVariableToText(stream, "attacks");

  stream << endl << "}" << endl << endl;
  stream << "CreatureTemplates:addCreatureTemplate(" << luaObjectName << ", \"" << luaObjectName << "\")";

  return data;
}

void CreatureObject::attacksVariableToText(QTextStream& stream, const QString& varName) {
  stream << "\t" << varName << " = {";

  QMapIterator<QString, QString> i(attacks);

  while (i.hasNext()) {
    i.next();

    stream << "\n\t\t{\"" << i.key() << "\",\"" << i.value() << "\"}";

    if (i.hasNext())
      stream << ",";
  }

  stream << endl << "\t}";
}



void CreatureObject::addDietBitmaskVariableToText(QTextStream& stream, const QString& varName) {
  QString data;
  QTextStream dataStream(&data);

  stream << "\t" << varName << " = ";

  if (diet == 0) {
    stream << "NONE";

    return;
  }

  if (hasDietFlag(HERBIVORE)) {
    if (!data.isEmpty())
      dataStream << " + ";

    dataStream << "HERBIVORE";
  }

  if (hasDietFlag(CARNIVORE)) {
    if (!data.isEmpty())
      dataStream << " + ";

    dataStream << "CARNIVORE";
  }

  stream << data;
}

void CreatureObject::addCreatureBitmaskVariableToText(QTextStream& stream, const QString& varName) {
  QString data;
  QTextStream dataStream(&data);

  stream << "\t" << varName << " = ";

  if (creatureBitmask == 0) {
    stream << "NONE";

    return;
  }

  if (hasCreatureFlag(PACK)) {
    if (!data.isEmpty())
      dataStream << " + ";

    dataStream << "PACK";
  }

  if (hasCreatureFlag(HERD)) {
    if (!data.isEmpty())
      dataStream << " + ";

    dataStream << "HERD";
  }


  if (hasCreatureFlag(KILLER)) {
    if (!data.isEmpty())
      dataStream << " + ";

    dataStream << "KILLER";
  }

  if (hasCreatureFlag(STALKER)) {
    if (!data.isEmpty())
      dataStream << " + ";

    dataStream << "STALKER";
  }

  if (hasCreatureFlag(HEALER)) {
    if (!data.isEmpty())
      dataStream << " + ";

    dataStream << "HEALER";
  }

  if (hasCreatureFlag(BABY)) {
    if (!data.isEmpty())
      dataStream << " + ";

    dataStream << "BABY";
  }

  if (hasCreatureFlag(LAIR)) {
    if (!data.isEmpty())
      dataStream << " + ";

    dataStream << "LAIR";
  }

  stream << data;
}

void CreatureObject::addPvpBitmaskVariableToText(QTextStream& stream, const QString& varName) {
  QString data;
  QTextStream dataStream(&data);

  stream << "\t" << varName << " = ";

  if (pvpBitmask == 0) {
    stream << "NONE";

    return;
  }

  if (hasPvpFlag(AGGRESSIVE)) {
    if (!data.isEmpty())
      dataStream << " + ";

    dataStream << "AGGRESSIVE";
  }

  if (hasPvpFlag(ATTACKABLE)) {
    if (!data.isEmpty())
      dataStream << " + ";

    dataStream << "ATTACKABLE";
  }

  if (hasPvpFlag(ENEMY)) {
    if (!data.isEmpty())
      dataStream << " + ";

    dataStream << "ENEMY";
  }

  if (hasPvpFlag(OVERT)) {
    if (!data.isEmpty())
      dataStream << " + ";

    dataStream << "OVERT";
  }

  stream << data;
}

void CreatureObject::setVariable(const QString& name, const QString& data) {
  if (name == "objectName") {
    objectName = getStringFromData(data);
  } else if (name == "pvpFaction") {
    pvpFaction = getStringFromData(data);
  } else if (name == "socialGroup") {
    socialGroup = getStringFromData(data);
  } else if (name == "faction") {
    faction = getStringFromData(data);
  } else if (name == "level") {
    level = data.toInt();
  } else if (name == "chanceHit") {
    chanceHit = data.toFloat();
  } else if (name == "damageMin") {
    damageMin = data.toInt();
  } else if (name == "damageMax") {
    damageMax = data.toInt();
  } else if (name == "baseHAM") {
    baseHAM = data.toInt();
  } else if (name == "baseHAMmax") {
    baseHAMmax = data.toInt();
  } else if (name == "armor") {
    armor = data.toInt();
  } else if (name == "resists") {
    parseResists(data);
  } else if (name == "meatType") {
    meatType = getStringFromData(data);
  } else if (name == "meatAmount") {
    meatAmount = data.toInt();
  } else if (name == "hideType") {
    hideType = getStringFromData(data);
  } else if (name == "hideAmount") {
    hideAmount = data.toInt();
  } else if (name == "boneType") {
    boneType = getStringFromData(data);
  } else if (name == "boneAmount") {
    boneAmount = data.toInt();
  } else if (name == "baseXp") {
    baseXp = data.toInt();
  } else if (name == "pvpBitmask") {
    parsePvpBitmask(data);
  } else if (name == "creatureBitmask") {
    parseCreatureBitmask(data);
  } else if (name == "diet") {
    parseDiet(data);
  } else if (name == "milk") {
    milk = data.toInt();
  } else if (name == "ferocity") {
    ferocity = data.toInt();
  } else if (name == "tamingChance") {
    tamingChance = data.toFloat();
  } else if (name == "templates") {
    parseStringVector(templates, data);
  } else if (name == "lootgroups") {
    parseStringVector(lootGroups, data);
  } else if (name == "weapons") {
    parseStringVector(weapons, data);
  } else if (name == "attacks") {
    parseAttacks(data);
  }
}

void CreatureObject::parsePvpBitmask(const QString& data) {
  pvpBitmask = 0;

  if (data.contains("AGGRESSIVE")) {
    pvpBitmask |= AGGRESSIVE;
  }

  if (data.contains("ATTACKABLE")) {
    pvpBitmask |= ATTACKABLE;
  }

  if (data.contains("ENEMY")) {
    pvpBitmask |= ENEMY;
  }

  if (data.contains("OVERT")) {
    pvpBitmask |= OVERT;
  }
}

void CreatureObject::parseDiet(const QString& data) {
  diet = 0;

  if (data.contains("HERBIVORE"))
    diet |= HERBIVORE;

  if (data.contains("CARNIVORE"))
    diet |= CARNIVORE;
}

void CreatureObject::parseCreatureBitmask(const QString& data) {
  creatureBitmask = 0;

  if (data.contains("PACK"))
    creatureBitmask |= PACK;

  if (data.contains("HERD"))
    creatureBitmask |= HERD;

  if (data.contains("KILLER"))
    creatureBitmask |= KILLER;

  if (data.contains("STALKER"))
    creatureBitmask |= STALKER;

  if (data.contains("HEALER"))
    creatureBitmask |= HEALER;

  if (data.contains("BABY"))
    creatureBitmask |= BABY;

  if (data.contains("LAIR"))
    creatureBitmask |= LAIR;
}

void CreatureObject::parseStringVector(QVector<QString>& vector, const QString& data) {
  QString dataContainer = data;
  dataContainer.remove(0, 1);

  while (dataContainer[0] != '}') {
    int idx = dataContainer.indexOf(",");

    if (idx != -1) {
      QString value = dataContainer.mid(0, idx);

      vector.append(getStringFromData(value));

      dataContainer.remove(0, idx + 1);
    } else if (dataContainer.size() > 1) { //
      idx = dataContainer.indexOf("}");

      QString value = dataContainer.mid(0, idx);

      vector.append(getStringFromData(value));

      return;
    }
  }

  return;
}

void CreatureObject::parseAttacks(const QString& data) {
  QString dataContainer = data;
  dataContainer.remove(0, 1);

  while (dataContainer[0] == '{') {
    dataContainer.remove(0, 1);

    QString key, value;

    int idx = dataContainer.indexOf(",");

    if (idx != -1) {
      QString keyData = dataContainer.mid(0, idx);

      key = getStringFromData(keyData);

      dataContainer.remove(0, idx + 1);

      idx = dataContainer.indexOf("}");

      QString valueData = dataContainer.mid(0, idx);

      value = getStringFromData(valueData);

      dataContainer.remove(0, idx + 1);

      attacks[key] = value;

      if (dataContainer[0] == ',')
        dataContainer.remove(0, 1);
    } else
      return;
  }
}

void CreatureObject::parseResists(const QString& data) {
  QString dataContainer = data;
  dataContainer.remove(0, 1);

  while (dataContainer[0] != '}') {
    int idx = dataContainer.indexOf(",");

    if (idx != -1) {
      QString value = dataContainer.mid(0, idx);

      resists.append(value.toFloat());

      dataContainer.remove(0, idx + 1);
    } else if (dataContainer.size() > 1) { //
      idx = dataContainer.indexOf("}");

      QString value = dataContainer.mid(0, idx);

      resists.append(value.toFloat());

      return;
    }
  }

  return;
}

