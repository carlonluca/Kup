/***************************************************************************
 *   Copyright Simon Persson                                               *
 *   simonpersson1@gmail.com                                               *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/

#ifndef RSYNCJOB_H
#define RSYNCJOB_H

#include "backupjob.h"

#include <KProcess>
#include <QElapsedTimer>

class KupDaemon;

class RsyncJob : public BackupJob
{
	Q_OBJECT

public:
	RsyncJob(const BackupPlan &pBackupPlan, const QString &pDestinationPath, const QString &pLogFilePath, KupDaemon *pKupDaemon);

protected slots:
	void performJob() Q_DECL_OVERRIDE;

protected slots:
	void slotRsyncStarted();
	void slotRsyncFinished(int pExitCode, QProcess::ExitStatus pExitStatus);
	void slotReadRsyncOutput();

protected:
	bool doKill() Q_DECL_OVERRIDE;
	bool doSuspend() Q_DECL_OVERRIDE;
	bool doResume() Q_DECL_OVERRIDE;

	KProcess mRsyncProcess;
	QElapsedTimer mInfoRateLimiter;
};

#endif // RSYNCJOB_H
