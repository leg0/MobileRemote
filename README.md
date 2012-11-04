MobileRemote
============

What is this?

Remote control app for N9 and a WinLIRC plug-in to support it.

The mobile app (currently N9 only) broadcasts (UDP port 9999) the remote
control codes which the WinLIRC plug-in reads and forwards to WinLIRC without
any modifications.


Installing the plug-in
----------------------

1) Compile the plug-in, put the resulting dll into WinLIRC/plugins directory.
2) Start WinLIRC, click "Reconfigure", select the plug-in, click OK.


Installing the mobile app
-------------------------

1) Compile the app in Qt Creator. You need Qt SDK with Harmattan bits.
2) Click 'Run' in Qt Creator.



TODO
----

  * publish the app in ovi store
  * build an installer for the WinLIRC plug-in
  * add more buttons to mobile app
  * add possibility to configure the buttons
  * ...