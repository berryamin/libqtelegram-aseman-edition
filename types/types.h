/*
 * Copyright 2014 Canonical Ltd.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; version 3.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 * Authors:
 *      Roberto Mier
 *      Tiago Herrmann
 */

#include "accountauthorizations.h"
#include "accountdaysttl.h"
#include "accountpassword.h"
#include "accountpasswordinputsettings.h"
#include "accountpasswordsettings.h"
#include "accountprivacyrules.h"
#include "accountsentchangephonecode.h"
#include "audio.h"
#include "authauthorization.h"
#include "authcheckedphone.h"
#include "authexportedauthorization.h"
#include "authorization.h"
#include "authpasswordrecovery.h"
#include "authsentcode.h"
#include "chat.h"
#include "chatfull.h"
#include "chatinvite.h"
#include "chatlocated.h"
#include "chatparticipant.h"
#include "chatparticipants.h"
#include "chatphoto.h"
#include "config.h"
#include "contact.h"
#include "contactblocked.h"
#include "contactfound.h"
#include "contactlink.h"
#include "contactsblocked.h"
#include "contactscontacts.h"
#include "contactsfound.h"
#include "contactsimportedcontacts.h"
#include "contactslink.h"
#include "contactssuggested.h"
#include "contactstatus.h"
#include "contactsuggested.h"
#include "dcoption.h"
#include "decryptedmessageaction.h"
#include "dialog.h"
#include "disabledfeature.h"
#include "document.h"
#include "documentattribute.h"
#include "encryptedchat.h"
#include "encryptedfile.h"
#include "encryptedmessage.h"
#include "exportedchatinvite.h"
#include "filelocation.h"
#include "geochatmessage.h"
#include "geochatslocated.h"
#include "geochatsmessages.h"
#include "geochatsstatedmessage.h"
#include "geopoint.h"
#include "helpappupdate.h"
#include "helpinvitetext.h"
#include "helpsupport.h"
#include "importedcontact.h"
#include "inputappevent.h"
#include "inputaudio.h"
#include "inputchatphoto.h"
#include "inputcontact.h"
#include "inputdocument.h"
#include "inputencryptedchat.h"
#include "inputencryptedfile.h"
#include "inputfile.h"
#include "inputfilelocation.h"
#include "inputgeochat.h"
#include "inputgeopoint.h"
#include "inputmedia.h"
#include "inputnotifypeer.h"
#include "inputpeer.h"
#include "inputpeernotifyevents.h"
#include "inputpeernotifysettings.h"
#include "inputphoto.h"
#include "inputphotocrop.h"
#include "inputprivacykey.h"
#include "inputprivacyrule.h"
#include "inputstickerset.h"
#include "inputuser.h"
#include "inputvideo.h"
#include "message.h"
#include "messageaction.h"
#include "messagemedia.h"
#include "messagesaffectedhistory.h"
#include "messagesaffectedmessages.h"
#include "messagesallstickers.h"
#include "messageschatfull.h"
#include "messageschats.h"
#include "messagesdhconfig.h"
#include "messagesdialogs.h"
#include "messagesfilter.h"
#include "messagesmessage.h"
#include "messagesmessages.h"
#include "messagessentencryptedmessage.h"
#include "messagessentmessage.h"
#include "messagesstickers.h"
#include "messagesstickerset.h"
#include "nearestdc.h"
#include "notifypeer.h"
#include "peer.h"
#include "peernotifyevents.h"
#include "peernotifysettings.h"
#include "photo.h"
#include "photosize.h"
#include "photosphoto.h"
#include "photosphotos.h"
#include "privacykey.h"
#include "privacyrule.h"
#include "receivednotifymessage.h"
#include "sendmessageaction.h"
#include "stickerpack.h"
#include "stickerset.h"
#include "storagefiletype.h"
#include "telegramtypeobject.h"
#include "update.h"
#include "updates.h"
#include "updatesdifference.h"
#include "updatesstate.h"
#include "uploadfile.h"
#include "user.h"
#include "userfull.h"
#include "userprofilephoto.h"
#include "userstatus.h"
#include "video.h"
#include "wallpaper.h"
#include "webpage.h"

