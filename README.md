# Tip_hackerank
+ Collect experience from hackerank exercises
+ https://stackoverflow.com/questions/46683300/use-64-bit-compiler-in-visual-studio
+ Switch evaluate integer type, so the expression can be integer or char type. But cannot floating-point type.
+ Switch is only used for equality, not like if is used for relational and logical operator.
+ Switch will automatically convert int to char. (hèn gì bị lúc làm luận văn máy MP3 mà hk biết)
+ C89 does not support delcare variable when initializing variable: for (int x = 0;;); C99 does support.
+ Return without value to use for void-function
+ C89 if no value is specified in non-void function, a garbegaed value will be return
+ C99 must has returned value.
+ Exit (return code) to exit the program -> OS. (EXIT_SUCCESS and EXIT_FAILURE).
+ When passing multimdimensional-arry,  declare an array, must specify size all dimensional but lefmost
+ Mua Tiki: 642k (500k tay cam + 142k sach)
+ C89: array with constant size, C99: array with variable length, even length is known when run-time.
+ Can add or subtrat pointer with an integer, only three arithmetic can be allowed in C are add/subtract pointer to an integer, and subtract two pointers (cannot add pointer + pointer, cannot add pointer + (float, double)number.
+ One way to initialize a pointer is assign zero to it.
+ Pointer function: A function hold a address to entry 
+ In C. malloc (void*) type will be converted automatically to left-side type (but it does not occur in C++).
+ Free function return previously allocated memory to the system 
+ In early C versions, no void-type defined, do vậy nếu không trả về giá trị thì mặc định là kiểu int
+ Hàm main return value to the calling process (operating system). If no value is return, most C compiler will return 0, but does not rely on it.
+ Đối với đệ quy, không tạo ra 1 bản sao (copy) của function mà tạo ra 1 tập (set) các biến variables và parameters
+ Hiếm khi đệ quy cải thiện được hiệu quả, vì the recursive version excecute a bit slower than the iterative equivalent code
+ Main advantages to recursive function is that you can you them to create a simpler and clearer version of several algorithms.
+ Khi thực hiện đệ quy phải có điều kiện if, buộc recursive function return mà không gọi thêm đệ quy
+ C original không có prototype function, được thêm vào trong C89 và cũng k yêu cầu phải có function prototype. Nhưng C++ thì phải có 
+ Seperate function với prototype vì tính thực tế
+ Đối với C khai báo: int name_func() ==> nghĩa là không có information của parameter. C compilers sẽ hiểu rằng không có paramter hoặc có paramters. Khác vs C++ ==> không có paramters!!!
+ Hàm vs tham số tùy biến variant paramters: int funcion(double x, float y, ...). Có dấu 3 chấm ở cuối. Phải có ít nhất 1 tham số trong khai báo prototype. In this case, function-prototype is iilegal int funcion(...)
+ Old-style function: return_type name_function(); ==> không có tham số trong hàm
+ Struct: pass call-by-value cần phải push struct tới stack khi function được thực thi -> với struct k nhiều members thì có thể nhưng khi quá nhiều member có thể dẫn tới giảm hiệu suất => Pass structure bằng pointer, chỉ có địa chỉ được đưa vào stack
+ C89: structure có thể nested 16 level, C99 có thể nested 63 levels
+ Khi declare unions, compiler sẽ cấp phát để có thể lưu trữ members lớn nhất của union đó. Vì members share chung bộ nhớ
+ Cách truy xuất unions cũng giống như structure, can use dot or arrow operator.
+ Bit-fields: type: length, với kiểu là int, signed hoặc unsigned và length là độ dài của bit.
+ Enum cách khai báo enum tag {symbol, symbol} variables, mỗi symbol đại diện cho 1 số nguyên
+ Getchar() -> putchar() -> getch() -> getche() -> puts() -> gets().
Getch() 
+ Scanf("%20s", str) => Số kí tự tối đa của str là 20
+ Put l precede c or s 
+ scanf("%*c", &variable) thì sẽ bỏ qua input có format là char. Tương tự với d scanf("%*d%c", &char_variable) sẽ bỏ qua input là số và đọc input là char
