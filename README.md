# photoeditor2024
 
A 2024 remake of my 2022 photo editor

## Windows notice
The project didn't work on Windows due to QTBUG-122716. I have now temporarily fixed the project until the bug is resolved, so if the project didn't work for you, it should now.

Also, QtCreator emits a lot of false clang-tidy warnings on Windows. See QTCREATORBUG-30441.

## Bug hunt
If I had a nickel for each Qt bug I found while working on this project, I'd have {bugs.count} nickels... 

Anyways, here they come:
- https://bugreports.qt.io/browse/QTBUG-122702
- https://bugreports.qt.io/browse/QTBUG-122716
- https://bugreports.qt.io/browse/QTCREATORBUG-30441
