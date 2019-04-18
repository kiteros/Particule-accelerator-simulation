#############################################################################
# Makefile for building: ProjetICC_QT
# Generated by qmake (3.1) (Qt 5.9.5)
# Project:  ProjetICC_QT.pro
# Template: subdirs
# Command: /usr/lib/qt5/bin/qmake -o Makefile ProjetICC_QT.pro -spec linux-g++
#############################################################################

MAKEFILE      = Makefile

first: make_first
QMAKE         = /usr/lib/qt5/bin/qmake
DEL_FILE      = rm -f
CHK_DIR_EXISTS= test -d
MKDIR         = mkdir -p
COPY          = cp -f
COPY_FILE     = cp -f
COPY_DIR      = cp -f -R
INSTALL_FILE  = install -m 644 -p
INSTALL_PROGRAM = install -m 755 -p
INSTALL_DIR   = cp -f -R
QINSTALL      = /usr/lib/qt5/bin/qmake -install qinstall
QINSTALL_PROGRAM = /usr/lib/qt5/bin/qmake -install qinstall -exe
DEL_FILE      = rm -f
SYMLINK       = ln -f -s
DEL_DIR       = rmdir
MOVE          = mv -f
TAR           = tar -cf
COMPRESS      = gzip -9f
DISTNAME      = ProjetICC_QT1.0.0
DISTDIR = /home/jules/icc_projet\ 2/Icc_final/.tmp/ProjetICC_QT1.0.0
SUBTARGETS    =  \
		sub-general \
		sub-Qt \
		sub-Textview


sub-general-qmake_all:  FORCE
	@test -d general/ || mkdir -p general/
	cd general/ && $(QMAKE) -o Makefile /home/jules/icc_projet\ 2/Icc_final/general/general.pro -spec linux-g++
	cd general/ && $(MAKE) -f Makefile qmake_all
sub-general: FORCE
	@test -d general/ || mkdir -p general/
	cd general/ && ( test -e Makefile || $(QMAKE) -o Makefile /home/jules/icc_projet\ 2/Icc_final/general/general.pro -spec linux-g++ ) && $(MAKE) -f Makefile
sub-general-make_first: FORCE
	@test -d general/ || mkdir -p general/
	cd general/ && ( test -e Makefile || $(QMAKE) -o Makefile /home/jules/icc_projet\ 2/Icc_final/general/general.pro -spec linux-g++ ) && $(MAKE) -f Makefile 
sub-general-all: FORCE
	@test -d general/ || mkdir -p general/
	cd general/ && ( test -e Makefile || $(QMAKE) -o Makefile /home/jules/icc_projet\ 2/Icc_final/general/general.pro -spec linux-g++ ) && $(MAKE) -f Makefile all
sub-general-clean: FORCE
	@test -d general/ || mkdir -p general/
	cd general/ && ( test -e Makefile || $(QMAKE) -o Makefile /home/jules/icc_projet\ 2/Icc_final/general/general.pro -spec linux-g++ ) && $(MAKE) -f Makefile clean
sub-general-distclean: FORCE
	@test -d general/ || mkdir -p general/
	cd general/ && ( test -e Makefile || $(QMAKE) -o Makefile /home/jules/icc_projet\ 2/Icc_final/general/general.pro -spec linux-g++ ) && $(MAKE) -f Makefile distclean
sub-general-install_subtargets: FORCE
	@test -d general/ || mkdir -p general/
	cd general/ && ( test -e Makefile || $(QMAKE) -o Makefile /home/jules/icc_projet\ 2/Icc_final/general/general.pro -spec linux-g++ ) && $(MAKE) -f Makefile install
sub-general-uninstall_subtargets: FORCE
	@test -d general/ || mkdir -p general/
	cd general/ && ( test -e Makefile || $(QMAKE) -o Makefile /home/jules/icc_projet\ 2/Icc_final/general/general.pro -spec linux-g++ ) && $(MAKE) -f Makefile uninstall
sub-Qt-qmake_all:  FORCE
	@test -d Qt/ || mkdir -p Qt/
	cd Qt/ && $(QMAKE) -o Makefile /home/jules/icc_projet\ 2/Icc_final/Qt/Qt.pro -spec linux-g++
	cd Qt/ && $(MAKE) -f Makefile qmake_all
sub-Qt: FORCE
	@test -d Qt/ || mkdir -p Qt/
	cd Qt/ && ( test -e Makefile || $(QMAKE) -o Makefile /home/jules/icc_projet\ 2/Icc_final/Qt/Qt.pro -spec linux-g++ ) && $(MAKE) -f Makefile
sub-Qt-make_first: FORCE
	@test -d Qt/ || mkdir -p Qt/
	cd Qt/ && ( test -e Makefile || $(QMAKE) -o Makefile /home/jules/icc_projet\ 2/Icc_final/Qt/Qt.pro -spec linux-g++ ) && $(MAKE) -f Makefile 
sub-Qt-all: FORCE
	@test -d Qt/ || mkdir -p Qt/
	cd Qt/ && ( test -e Makefile || $(QMAKE) -o Makefile /home/jules/icc_projet\ 2/Icc_final/Qt/Qt.pro -spec linux-g++ ) && $(MAKE) -f Makefile all
sub-Qt-clean: FORCE
	@test -d Qt/ || mkdir -p Qt/
	cd Qt/ && ( test -e Makefile || $(QMAKE) -o Makefile /home/jules/icc_projet\ 2/Icc_final/Qt/Qt.pro -spec linux-g++ ) && $(MAKE) -f Makefile clean
sub-Qt-distclean: FORCE
	@test -d Qt/ || mkdir -p Qt/
	cd Qt/ && ( test -e Makefile || $(QMAKE) -o Makefile /home/jules/icc_projet\ 2/Icc_final/Qt/Qt.pro -spec linux-g++ ) && $(MAKE) -f Makefile distclean
sub-Qt-install_subtargets: FORCE
	@test -d Qt/ || mkdir -p Qt/
	cd Qt/ && ( test -e Makefile || $(QMAKE) -o Makefile /home/jules/icc_projet\ 2/Icc_final/Qt/Qt.pro -spec linux-g++ ) && $(MAKE) -f Makefile install
sub-Qt-uninstall_subtargets: FORCE
	@test -d Qt/ || mkdir -p Qt/
	cd Qt/ && ( test -e Makefile || $(QMAKE) -o Makefile /home/jules/icc_projet\ 2/Icc_final/Qt/Qt.pro -spec linux-g++ ) && $(MAKE) -f Makefile uninstall
sub-Textview-qmake_all:  FORCE
	@test -d Textview/ || mkdir -p Textview/
	cd Textview/ && $(QMAKE) -o Makefile /home/jules/icc_projet\ 2/Icc_final/Textview/Textview.pro -spec linux-g++
	cd Textview/ && $(MAKE) -f Makefile qmake_all
sub-Textview: FORCE
	@test -d Textview/ || mkdir -p Textview/
	cd Textview/ && ( test -e Makefile || $(QMAKE) -o Makefile /home/jules/icc_projet\ 2/Icc_final/Textview/Textview.pro -spec linux-g++ ) && $(MAKE) -f Makefile
sub-Textview-make_first: FORCE
	@test -d Textview/ || mkdir -p Textview/
	cd Textview/ && ( test -e Makefile || $(QMAKE) -o Makefile /home/jules/icc_projet\ 2/Icc_final/Textview/Textview.pro -spec linux-g++ ) && $(MAKE) -f Makefile 
sub-Textview-all: FORCE
	@test -d Textview/ || mkdir -p Textview/
	cd Textview/ && ( test -e Makefile || $(QMAKE) -o Makefile /home/jules/icc_projet\ 2/Icc_final/Textview/Textview.pro -spec linux-g++ ) && $(MAKE) -f Makefile all
sub-Textview-clean: FORCE
	@test -d Textview/ || mkdir -p Textview/
	cd Textview/ && ( test -e Makefile || $(QMAKE) -o Makefile /home/jules/icc_projet\ 2/Icc_final/Textview/Textview.pro -spec linux-g++ ) && $(MAKE) -f Makefile clean
sub-Textview-distclean: FORCE
	@test -d Textview/ || mkdir -p Textview/
	cd Textview/ && ( test -e Makefile || $(QMAKE) -o Makefile /home/jules/icc_projet\ 2/Icc_final/Textview/Textview.pro -spec linux-g++ ) && $(MAKE) -f Makefile distclean
sub-Textview-install_subtargets: FORCE
	@test -d Textview/ || mkdir -p Textview/
	cd Textview/ && ( test -e Makefile || $(QMAKE) -o Makefile /home/jules/icc_projet\ 2/Icc_final/Textview/Textview.pro -spec linux-g++ ) && $(MAKE) -f Makefile install
sub-Textview-uninstall_subtargets: FORCE
	@test -d Textview/ || mkdir -p Textview/
	cd Textview/ && ( test -e Makefile || $(QMAKE) -o Makefile /home/jules/icc_projet\ 2/Icc_final/Textview/Textview.pro -spec linux-g++ ) && $(MAKE) -f Makefile uninstall

Makefile: ProjetICC_QT.pro /usr/lib/x86_64-linux-gnu/qt5/mkspecs/linux-g++/qmake.conf /usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/spec_pre.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/unix.conf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/linux.conf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/sanitize.conf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/gcc-base.conf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/gcc-base-unix.conf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/g++-base.conf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/g++-unix.conf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/qconfig.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_accessibility_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_bootstrap_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_concurrent.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_concurrent_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_core.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_core_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_dbus.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_dbus_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_devicediscovery_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_egl_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_eglfs_kms_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_eglfsdeviceintegration_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_eventdispatcher_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_fb_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_fontdatabase_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_glx_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_gui.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_gui_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_input_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_kms_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_linuxaccessibility_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_network.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_network_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_opengl.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_opengl_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_openglextensions.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_openglextensions_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_platformcompositor_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_printsupport.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_printsupport_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_service_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_sql.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_sql_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_testlib.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_testlib_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_theme_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_widgets.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_widgets_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_xcb_qpa_lib_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_xml.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_xml_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/qt_functions.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/qt_config.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/linux-g++/qmake.conf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/spec_post.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/exclusive_builds.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/toolchain.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/default_pre.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/resolve_config.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/default_post.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/warn_on.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/qmake_use.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/file_copies.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/testcase_targets.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/exceptions.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/yacc.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/lex.prf \
		ProjetICC_QT.pro
	$(QMAKE) -o Makefile ProjetICC_QT.pro -spec linux-g++
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/spec_pre.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/unix.conf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/linux.conf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/sanitize.conf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/gcc-base.conf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/gcc-base-unix.conf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/g++-base.conf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/g++-unix.conf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/qconfig.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_accessibility_support_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_bootstrap_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_concurrent.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_concurrent_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_core.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_core_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_dbus.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_dbus_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_devicediscovery_support_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_egl_support_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_eglfs_kms_support_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_eglfsdeviceintegration_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_eventdispatcher_support_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_fb_support_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_fontdatabase_support_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_glx_support_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_gui.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_gui_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_input_support_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_kms_support_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_linuxaccessibility_support_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_network.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_network_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_opengl.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_opengl_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_openglextensions.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_openglextensions_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_platformcompositor_support_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_printsupport.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_printsupport_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_service_support_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_sql.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_sql_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_testlib.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_testlib_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_theme_support_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_widgets.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_widgets_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_xcb_qpa_lib_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_xml.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_xml_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/qt_functions.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/qt_config.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/linux-g++/qmake.conf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/spec_post.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/exclusive_builds.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/toolchain.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/default_pre.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/resolve_config.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/default_post.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/warn_on.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/qmake_use.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/file_copies.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/testcase_targets.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/exceptions.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/yacc.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/lex.prf:
ProjetICC_QT.pro:
qmake: FORCE
	@$(QMAKE) -o Makefile ProjetICC_QT.pro -spec linux-g++

qmake_all: sub-general-qmake_all sub-Qt-qmake_all sub-Textview-qmake_all FORCE

make_first: sub-general-make_first sub-Qt-make_first sub-Textview-make_first  FORCE
all: sub-general-all sub-Qt-all sub-Textview-all  FORCE
clean: sub-general-clean sub-Qt-clean sub-Textview-clean  FORCE
distclean: sub-general-distclean sub-Qt-distclean sub-Textview-distclean  FORCE
	-$(DEL_FILE) Makefile
	-$(DEL_FILE) .qmake.stash
install_subtargets: sub-general-install_subtargets sub-Qt-install_subtargets sub-Textview-install_subtargets FORCE
uninstall_subtargets: sub-general-uninstall_subtargets sub-Qt-uninstall_subtargets sub-Textview-uninstall_subtargets FORCE

sub-general-check:
	@test -d general/ || mkdir -p general/
	cd general/ && ( test -e Makefile || $(QMAKE) -o Makefile /home/jules/icc_projet\ 2/Icc_final/general/general.pro -spec linux-g++ ) && $(MAKE) -f Makefile check
sub-Qt-check:
	@test -d Qt/ || mkdir -p Qt/
	cd Qt/ && ( test -e Makefile || $(QMAKE) -o Makefile /home/jules/icc_projet\ 2/Icc_final/Qt/Qt.pro -spec linux-g++ ) && $(MAKE) -f Makefile check
sub-Textview-check:
	@test -d Textview/ || mkdir -p Textview/
	cd Textview/ && ( test -e Makefile || $(QMAKE) -o Makefile /home/jules/icc_projet\ 2/Icc_final/Textview/Textview.pro -spec linux-g++ ) && $(MAKE) -f Makefile check
check: sub-general-check sub-Qt-check sub-Textview-check

sub-general-benchmark:
	@test -d general/ || mkdir -p general/
	cd general/ && ( test -e Makefile || $(QMAKE) -o Makefile /home/jules/icc_projet\ 2/Icc_final/general/general.pro -spec linux-g++ ) && $(MAKE) -f Makefile benchmark
sub-Qt-benchmark:
	@test -d Qt/ || mkdir -p Qt/
	cd Qt/ && ( test -e Makefile || $(QMAKE) -o Makefile /home/jules/icc_projet\ 2/Icc_final/Qt/Qt.pro -spec linux-g++ ) && $(MAKE) -f Makefile benchmark
sub-Textview-benchmark:
	@test -d Textview/ || mkdir -p Textview/
	cd Textview/ && ( test -e Makefile || $(QMAKE) -o Makefile /home/jules/icc_projet\ 2/Icc_final/Textview/Textview.pro -spec linux-g++ ) && $(MAKE) -f Makefile benchmark
benchmark: sub-general-benchmark sub-Qt-benchmark sub-Textview-benchmark
install:install_subtargets  FORCE

uninstall: uninstall_subtargets FORCE

FORCE:

dist: distdir FORCE
	(cd `dirname $(DISTDIR)` && $(TAR) $(DISTNAME).tar $(DISTNAME) && $(COMPRESS) $(DISTNAME).tar) && $(MOVE) `dirname $(DISTDIR)`/$(DISTNAME).tar.gz . && $(DEL_FILE) -r $(DISTDIR)

distdir: sub-general-distdir sub-Qt-distdir sub-Textview-distdir FORCE
	@test -d $(DISTDIR) || mkdir -p $(DISTDIR)
	$(COPY_FILE) --parents /usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/spec_pre.prf /usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/unix.conf /usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/linux.conf /usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/sanitize.conf /usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/gcc-base.conf /usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/gcc-base-unix.conf /usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/g++-base.conf /usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/g++-unix.conf /usr/lib/x86_64-linux-gnu/qt5/mkspecs/qconfig.pri /usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_accessibility_support_private.pri /usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_bootstrap_private.pri /usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_concurrent.pri /usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_concurrent_private.pri /usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_core.pri /usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_core_private.pri /usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_dbus.pri /usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_dbus_private.pri /usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_devicediscovery_support_private.pri /usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_egl_support_private.pri /usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_eglfs_kms_support_private.pri /usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_eglfsdeviceintegration_private.pri /usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_eventdispatcher_support_private.pri /usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_fb_support_private.pri /usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_fontdatabase_support_private.pri /usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_glx_support_private.pri /usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_gui.pri /usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_gui_private.pri /usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_input_support_private.pri /usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_kms_support_private.pri /usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_linuxaccessibility_support_private.pri /usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_network.pri /usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_network_private.pri /usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_opengl.pri /usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_opengl_private.pri /usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_openglextensions.pri /usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_openglextensions_private.pri /usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_platformcompositor_support_private.pri /usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_printsupport.pri /usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_printsupport_private.pri /usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_service_support_private.pri /usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_sql.pri /usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_sql_private.pri /usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_testlib.pri /usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_testlib_private.pri /usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_theme_support_private.pri /usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_widgets.pri /usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_widgets_private.pri /usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_xcb_qpa_lib_private.pri /usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_xml.pri /usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_xml_private.pri /usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/qt_functions.prf /usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/qt_config.prf /usr/lib/x86_64-linux-gnu/qt5/mkspecs/linux-g++/qmake.conf /usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/spec_post.prf /usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/exclusive_builds.prf /usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/toolchain.prf /usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/default_pre.prf /usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/resolve_config.prf /usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/default_post.prf /usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/warn_on.prf /usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/qmake_use.prf /usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/file_copies.prf /usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/testcase_targets.prf /usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/exceptions.prf /usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/yacc.prf /usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/lex.prf ProjetICC_QT.pro $(DISTDIR)/

sub-general-distdir: FORCE
	@test -d general/ || mkdir -p general/
	cd general/ && ( test -e Makefile || $(QMAKE) -o Makefile /home/jules/icc_projet\ 2/Icc_final/general/general.pro -spec linux-g++ ) && $(MAKE) -e -f Makefile distdir DISTDIR=$(DISTDIR)/general

sub-Qt-distdir: FORCE
	@test -d Qt/ || mkdir -p Qt/
	cd Qt/ && ( test -e Makefile || $(QMAKE) -o Makefile /home/jules/icc_projet\ 2/Icc_final/Qt/Qt.pro -spec linux-g++ ) && $(MAKE) -e -f Makefile distdir DISTDIR=$(DISTDIR)/Qt

sub-Textview-distdir: FORCE
	@test -d Textview/ || mkdir -p Textview/
	cd Textview/ && ( test -e Makefile || $(QMAKE) -o Makefile /home/jules/icc_projet\ 2/Icc_final/Textview/Textview.pro -spec linux-g++ ) && $(MAKE) -e -f Makefile distdir DISTDIR=$(DISTDIR)/Textview
