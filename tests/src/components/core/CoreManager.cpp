#include "../../app/Database.hpp"

#include "CoreManager.hpp"

// ===================================================================

CoreManager *CoreManager::m_instance = nullptr;

CoreManager::CoreManager (QObject *parent) : m_core(
  linphone::Factory::get()->createCore(nullptr, "", "", nullptr)
) {
  setDatabasesPaths();
}

void CoreManager::setDatabasesPaths () {
  std::string database_path;

  database_path = Database::getFriendsListPath();
  if (database_path.length() == 0)
    qFatal("Unable to get friends list database path.");
  m_core->setFriendsDatabasePath(database_path);

  database_path = Database::getCallHistoryPath();
  if (database_path.length() == 0)
    qFatal("Unable to get call history database path.");
  m_core->setCallLogsDatabasePath(database_path);

  database_path = Database::getMessageHistoryPath();
  if (database_path.length() == 0)
    qFatal("Unable to get message history database path.");

  // FIXME.
  // m_core->setChatDatabasePath(database_path);
}
