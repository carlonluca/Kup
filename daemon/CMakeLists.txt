
include_directories("../settings")

set(kupdaemon_SRCS
main.cpp
kupdaemon.cpp
planexecutor.cpp
edexecutor.cpp
fsexecutor.cpp
backupjob.cpp
bupjob.cpp
bupverificationjob.cpp
buprepairjob.cpp
rsyncjob.cpp
../settings/backupplan.cpp
../settings/kupsettings.cpp
../settings/kuputils.cpp
)

ecm_qt_declare_logging_category(kupdaemon_SRCS
    HEADER kupdaemon_debug.h
    IDENTIFIER KUPDAEMON
    CATEGORY_NAME kup.daemon
    DEFAULT_SEVERITY Debug
)

kf5_add_kdeinit_executable(kup-daemon ${kupdaemon_SRCS})
target_link_libraries(kdeinit_kup-daemon
Qt5::Core
Qt5::DBus
Qt5::Gui
KF5::ConfigCore
KF5::KIOCore
KF5::KIOFileWidgets
KF5::IdleTime
KF5::I18n
KF5::JobWidgets
KF5::Solid
KF5::Notifications
KF5::CoreAddons
KF5::DBusAddons
)

########### install files ###############
install(TARGETS kup-daemon ${INSTALL_TARGETS_DEFAULT_ARGS})
install(TARGETS kdeinit_kup-daemon ${INSTALL_TARGETS_DEFAULT_ARGS})
install(FILES kup-daemon.desktop DESTINATION ${AUTOSTART_INSTALL_DIR})
install(FILES kupdaemon.notifyrc DESTINATION ${KNOTIFYRC_INSTALL_DIR})

