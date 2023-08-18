// --- Khai báo thư viện tay cầm PS3 ---
#include <Ps3Controller.h>

// --- Khai báo biến để gán địa chỉ MAC của ESP32 ---
#define MAC_ADDRESS "E0:5A:1B:A1:F6:C8"

// --- Khai báo các biến cần sử dụng (người chơi - mức pin) ---
int player = 0;
int battery = 0;

// --- Tạo hàm con gán các nút và in tín hiệu ra màn hình ---
void PS3_State()
{
    // --- Các sự kiện Digital của các nút: Gạch chéo / Vuông / Tam giác / Tròn ---
    if( Ps3.event.button_down.cross )
        Serial.println("Bắt đầu nhấn nút: Gạch chéo");
    if( Ps3.event.button_up.cross )
        Serial.println("Thả nút: Gạch chéo");

    if( Ps3.event.button_down.square )
        Serial.println("Bắt đầu nhấn nút: Vuông");
    if( Ps3.event.button_up.square )
        Serial.println("Thả nút: Vuông");

    if( Ps3.event.button_down.triangle )
        Serial.println("Bắt đầu nhấn nút: Tam giác");
    if( Ps3.event.button_up.triangle )
        Serial.println("Thả nút: Tam giác");

    if( Ps3.event.button_down.circle )
        Serial.println("Bắt đầu nhấn nút: Tròn");
    if( Ps3.event.button_up.circle )
        Serial.println("Thả nút: Tròn");

    // --- Những sự kiện Digital các nút: D-pad ---
    if( Ps3.event.button_down.up )
        Serial.println("Bắt đầu nhấn nút: Lên");
    if( Ps3.event.button_up.up )
        Serial.println("Thả nút: Lên");

    if( Ps3.event.button_down.right )
        Serial.println("Bắt đầu nhấn nút: Phải");
    if( Ps3.event.button_up.right )
        Serial.println("Thả nút: Phải");

    if( Ps3.event.button_down.down )
        Serial.println("Bắt đầu nhấn nút: Xuống");
    if( Ps3.event.button_up.down )
        Serial.println("Thả nút: Xuống");

    if( Ps3.event.button_down.left )
        Serial.println("Bắt đầu nhấn nút: Trái");
    if( Ps3.event.button_up.left )
        Serial.println("Thả nút: Trái");

    // --- Những sự kiện Digital của các nút: Vai tay cầm ---
    if( Ps3.event.button_down.l1 )
        Serial.println("Bắt đầu nhấn nút vai: L1");
    if( Ps3.event.button_up.l1 )
        Serial.println("Thả nút: L1");

    if( Ps3.event.button_down.r1 )
        Serial.println("Bắt đầu nhấn nút vai: R1");
    if( Ps3.event.button_up.r1 )
        Serial.println("Thả nút: R1");

    // --- Những sự kiện Digital của các nút: Cò tay cầm ---
    if( Ps3.event.button_down.l2 )
        Serial.println("Bắt đầu nhấn nút cò: L2");
    if( Ps3.event.button_up.l2 )
        Serial.println("Thả nút cò: L2");

    if( Ps3.event.button_down.r2 )
        Serial.println("Bắt đầu nhấn nút: R2");
    if( Ps3.event.button_up.r2 )
        Serial.println("Thả nút: R2");

    // --- Những sự kiện Digital của nút nhấn: Joystick ---
    if( Ps3.event.button_down.l3 )
        Serial.println("Bắt đầu nhấn nút joystick: L3");
    if( Ps3.event.button_up.l3 )
        Serial.println("Thả nút nút joystick: L3");

    if( Ps3.event.button_down.r3 )
        Serial.println("Bắt đầu nhấn nút joystick: R3");
    if( Ps3.event.button_up.r3 )
        Serial.println("Thả nút joystick: R3");

    // --- Những sự kiện Digital của các nút: Lựa chọn / Khởi động / PlayStation ---
    if( Ps3.event.button_down.select )
        Serial.println("Bắt đầu nhấn nút: Lựa chọn");
    if( Ps3.event.button_up.select )
        Serial.println("Thả nút: Lựa chọn");

    if( Ps3.event.button_down.start )
        Serial.println("Bắt đầu nhấn nút: Khởi động");
    if( Ps3.event.button_up.start )
        Serial.println("Thả nút: Khởi động");

    if( Ps3.event.button_down.ps )
        Serial.println("Bắt đầu nhấn nút: PlayStation");
    if( Ps3.event.button_up.ps )
        Serial.println("Thả nút: PlayStation");


    // --- Những sự kiện Analog của các nút: Joystick ---
   if( abs(Ps3.event.analog_changed.stick.lx) + abs(Ps3.event.analog_changed.stick.ly) > 2 ){
       Serial.print("Di chuyển Joystick bên trái:");
       Serial.print(" x = "); Serial.print(Ps3.data.analog.stick.lx, DEC);
       Serial.print(" y = "); Serial.print(Ps3.data.analog.stick.ly, DEC);
       Serial.println();
    }

   if( abs(Ps3.event.analog_changed.stick.rx) + abs(Ps3.event.analog_changed.stick.ry) > 2 ){
       Serial.print("Di chuyển Joystick bên phải:");
       Serial.print(" x = "); Serial.print(Ps3.data.analog.stick.rx, DEC);
       Serial.print(" y = "); Serial.print(Ps3.data.analog.stick.ry, DEC);
       Serial.println();
   }

   // --- Những sự kiện Analog của các nút: D-pad ---
   if( abs(Ps3.event.analog_changed.button.up) ){
       Serial.print("Đang nhấn nút - Lên: ");
       Serial.println(Ps3.data.analog.button.up, DEC);
   }

   if( abs(Ps3.event.analog_changed.button.right) ){
       Serial.print("Đang nhấn nút - Phải: ");
       Serial.println(Ps3.data.analog.button.right, DEC);
   }

   if( abs(Ps3.event.analog_changed.button.down) ){
       Serial.print("Đang nhấn nút - Xuống: ");
       Serial.println(Ps3.data.analog.button.down, DEC);
   }

   if( abs(Ps3.event.analog_changed.button.left) ){
       Serial.print("Đang nhấn nút - Trái: ");
       Serial.println(Ps3.data.analog.button.left, DEC);
   }

   // --- Những sự kiện Analog của các nút: Vai / Cò tay cầm ---
   if( abs(Ps3.event.analog_changed.button.l1)){
       Serial.print("Đang nhấn nút vai - Trái: ");
       Serial.println(Ps3.data.analog.button.l1, DEC);
   }

   if( abs(Ps3.event.analog_changed.button.r1) ){
       Serial.print("Đang nhấn nút vai - Phải: ");
       Serial.println(Ps3.data.analog.button.r1, DEC);
   }

   if( abs(Ps3.event.analog_changed.button.l2) ){
       Serial.print("Đang nhấn nút cò - Trái: ");
       Serial.println(Ps3.data.analog.button.l2, DEC);
   }

   if( abs(Ps3.event.analog_changed.button.r2) ){
       Serial.print("Đang nhấn nút cò - Phải: ");
       Serial.println(Ps3.data.analog.button.r2, DEC);
   }

   // --- Những sự kiện Analog của các nút: Tam giác/Tròn/Gạch chéo/Vuông ---
   if( abs(Ps3.event.analog_changed.button.triangle)){
       Serial.print("Đang nhấn nút - Tam giác: ");
       Serial.println(Ps3.data.analog.button.triangle, DEC);
   }

   if( abs(Ps3.event.analog_changed.button.circle) ){
       Serial.print("Đang nhấn nút - Tròn: ");
       Serial.println(Ps3.data.analog.button.circle, DEC);
   }

   if( abs(Ps3.event.analog_changed.button.cross) ){
       Serial.print("Đang nhấn nút - Gạch chéo: ");
       Serial.println(Ps3.data.analog.button.cross, DEC);
   }

   if( abs(Ps3.event.analog_changed.button.square) ){
       Serial.print("Đang nhấn nút - Vuông: ");
       Serial.println(Ps3.data.analog.button.square, DEC);
   }

   // --- Những sự kiện: Mức pin ---
    if( battery != Ps3.data.status.battery ){
        battery = Ps3.data.status.battery;
        Serial.print("Mức pin của tay cầm: ");
        if( battery == ps3_status_battery_charging )      Serial.println("Đang sạc");
        else if( battery == ps3_status_battery_full )     Serial.println("ĐẦY");
        else if( battery == ps3_status_battery_high )     Serial.println("CAO");
        else if( battery == ps3_status_battery_low)       Serial.println("THẤP");
        else if( battery == ps3_status_battery_dying )    Serial.println("YẾU");
        else if( battery == ps3_status_battery_shutdown ) Serial.println("TẮT NGUỒN");
        else Serial.println("KHÔNG XÁC ĐỊNH");
    }

}

// --- Tạo hàm con thực thi lệnh nếu đã kết nối ---
void PS3_onConnect(){
    Serial.println("Đã kết nối.");
}

// --- Hàm khởi tạo, thiết lập, định nghĩa các tác vụ, biến ---
void setup()
{
    // --- Khởi tạo biến Serial (Chuẩn baud ESP32: 115200) ---
    Serial.begin(115200);

    // --- Gán hàm dữ liệu PS3 ---
    Ps3.attach(PS3_State);
    // --- Gán hàm kiểm tra kết nối PS3 ---
    Ps3.attachOnConnect(PS3_onConnect);
    // --- Khởi tạo PS3 ---
    Ps3.begin(MAC_ADDRESS);

    // --- In trạng thái nếu đã thực thi được các lệnh trên ---
    Serial.println("Sẵn sàng.");
}
// --- Hàm thực thi lệnh liên tục theo vòng tuần hoàn
void loop()
{
    // --- Không thực thi bất kì lệnh gì nếu không kết nối được PS3 ---
    if(!Ps3.isConnected())
        return;

    // --- Những đèn LED đánh dấu người chơi ---
    // Serial.print("Thiết lập những đèn LED đến người chơi "); Serial.println(player, DEC);
    // Ps3.setPlayer(player);

    // player += 1;
    // if(player > 10) player = 0;


    // --- Những nút nhấn Digital: Gạch chéo / Vuông / Tam giác / Tròn ---
    if( Ps3.data.button.cross && Ps3.data.button.down )
        Serial.println("Đang nhấn đồng thời các nút: Gạch chéo - Xuống");
    if( Ps3.data.button.square && Ps3.data.button.left )
        Serial.println("Đang nhấn đồng thời các nút: Vuông - Trái");
    if( Ps3.data.button.triangle && Ps3.data.button.up )
        Serial.println("Đang nhấn đồng thời các nút: Tam giác - Lên");
    if( Ps3.data.button.circle && Ps3.data.button.right )
        Serial.println("Đang nhấn đồng thời các nút: Tròn - Phải");

    if( Ps3.data.button.l1 && Ps3.data.button.r1 )
        Serial.println("Đang nhấn đồng thời các nút vai: Trái - Phải");
    if( Ps3.data.button.l2 && Ps3.data.button.r2 )
        Serial.println("Đang nhấn đồng thời các nút cò: Trái - Phải");
    if( Ps3.data.button.l3 && Ps3.data.button.r3 )
        Serial.println("Đang nhấn đồng thời các nút Joystick: Trái - Phải");
    if( Ps3.data.button.select && Ps3.data.button.start )
        Serial.println("Đang nhấn đồng thời các nút: Lựa chọn - Khởi động");

    // --- Độ trễ ---
    delay(2000);
}