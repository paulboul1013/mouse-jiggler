# mouse-jiggler

## 介紹
使用libevdev創建一個虛擬滑鼠，並且在不動滑鼠情況下，自動左右上下移動
>但本人是用wsl去跑，因為WSL2 與 Windows 之間的系統架構限制，導致虛擬輸入無法回傳給宿主機，導致無法讓虛擬滑鼠移動

## kernel uinput module 介紹
>uinput 是一個內核模塊，它使得從用戶空間模擬輸入設備成為可能。通過寫入 /dev/uinput (或 /dev/input/uinput) 設備，一個進程可以創建一個具有特定功能的虛擬輸入設備。 一旦創建了這個虛擬設備，進程就可以通過它發送事件，這些事件將被傳遞給用戶空間和內核消費者。

文檔中是建議使用libevdev這封裝庫，比較不會出錯

## 基本libevdev介紹
主要用於處理核心（Kernel）的 **evdev** (Event Device) 介面。

簡單來說，它是 Linux 核心輸入子系統（Input Subsystem）與上層應用軟體（如 libinput、X.Org 驅動程式或 Wayland 合成器）之間的**包裝層（Wrapper）**。

## 參考
https://www.youtube.com/watch?v=Ax8FgyCsQNU&t=501s
https://jasonblog.github.io/note/linux_system/1513.html
https://www.freedesktop.org/software/libevdev/doc/latest/
https://www.kernel.org/doc/html/v4.12/input/uinput.html
https://www.freedesktop.org/software/libevdev/doc/latest/group__uinput.html
