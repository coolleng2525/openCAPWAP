/*******************************************************************************************
 * Copyright (c) 2006-7 Laboratorio di Sistemi di Elaborazione e Bioingegneria Informatica *
 *                      Universita' Campus BioMedico - Italy                               *
 *                                                                                         *
 * This program is free software; you can redistribute it and/or modify it under the terms *
 * of the GNU General Public License as published by the Free Software Foundation; either  *
 * version 2 of the License, or (at your option) any later version.                        *
 *                                                                                         *
 * This program is distributed in the hope that it will be useful, but WITHOUT ANY         *
 * WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A 	       *
 * PARTICULAR PURPOSE. See the GNU General Public License for more details.                *
 *                                                                                         *
 * You should have received a copy of the GNU General Public License along with this       *
 * program; if not, write to the:                                                          *
 * Free Software Foundation, Inc., 59 Temple Place - Suite 330, Boston,                    *
 * MA  02111-1307, USA.                                                                    *
 *                                                                                         *
 * In addition, as a special exception, the copyright holders give permission to link the  *
 * code of portions of this program with the OpenSSL library under certain conditions as   *
 * described in each individual source file, and distribute linked combinations including  * 
 * the two. You must obey the GNU General Public License in all respects for all of the    *
 * code used other than OpenSSL.  If you modify file(s) with this exception, you may       *
 * extend this exception to your version of the file(s), but you are not obligated to do   *
 * so.  If you do not wish to do so, delete this exception statement from your version.    *
 * If you delete this exception statement from all source files in the program, then also  *
 * delete it here.                                                                         *
 * 
 * --------------------------------------------------------------------------------------- *
 * Project:  Capwap                                                                        *
 *                                                                                         *
 * Author :  Ludovico Rossi (ludo@bluepixysw.com)                                          *  
 *           Del Moro Andrea (andrea_delmoro@libero.it)                                    *
 *           Giovannini Federica (giovannini.federica@gmail.com)                           *
 *           Massimo Vellucci (m.vellucci@unicampus.it)                                    *
 *           Mauro Bisson (mauro.bis@gmail.com)                                            *
 *******************************************************************************************/


#ifndef __CAPWAP_CWLog_HEADER__
#define __CAPWAP_CWLog_HEADER__

extern char gLogFileName[];

__inline__ void CWVLog(const char *format, va_list args);
__inline__ void __CWLog(const char *format, ...);
__inline__ void __CWDebugLog(const char *format, ...);
__inline__ char *get_time_string();
void CWLogInitFile(char *fileName);
#define MY_LOG_FILE "/var/wtp/xxx_wtp.log"

#define DEBUG_LOG(format, args...) do{\
    FILE * fd = fopen(MY_LOG_FILE, "a+"); \
        if(fd < 0) {\
            printf("Can't open debug.log\n");\
        } else {\
            fprintf(fd, "[%s] %s:%d %s " format "\n", get_time_string(), __FILE__, __LINE__, __FUNCTION__,  ##args);\
            fclose(fd);\
        }\
    }while(0)
#define CWLog(format, args...) do{\
        __CWLog("[%s] %s:%d %s " format "\n", get_time_string(), __FILE__, __LINE__, __FUNCTION__,  ##args);\
        DEBUG_LOG(format, ##args);\
    }while(0)
#define CWDebugLog(format, args...) do{\
        __CWDebugLog("[%s] %s:%d %s " format "\n", get_time_string(), __FILE__, __LINE__, __FUNCTION__,  ##args);\
        DEBUG_LOG(format, ##args);\
    }while(0)

#endif
