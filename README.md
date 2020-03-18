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
+ fputc() và putc() là hai hàm có chức năng tương đương nhau(ghi vào file được chỉ bởi con tro FILE*), vì lý do tương thích với phiên bản cũ của C 
+ Tương tự là getc() và fgetc()
Text and binary streams differ in several ways:
+ The data read from a text stream is divided into lines which are terminated by newline ('\n') characters, while a binary stream is simply a long series of characters. A text stream might on some systems fail to handle lines more than 254 characters long (including the terminating newline character).
    ** On some systems, text files can contain only printing characters, horizontal tab characters, and newlines, and so text streams may not support other characters. However, binary streams can handle any character value.
    ** Space characters that are written immediately preceding a newline character in a text stream may disappear when the file is read in again.
    ** More generally, there need not be a one-to-one mapping between characters that are read from or written to a text stream, and the characters in the actual file. 
    
    
    #ifndef BSA_TASK
#define BSA_TASK
#include <stdint.h>
#include "define.h"
#include "errno.h"

#ifdef _WIN32
    #include <windows.h>
#else
    #include <unistd.h>
    #include <pthread.h>
#endif

#define MAX_TASK 128
#define NIL 0

typedef struct Thread {
    int32_t id;
    HANDLE thread;
} Thread_t;

extern bool continue_program;

int32_t bsakr_create_tsk(int8_t *name, int32_t priority, int32_t stacksize, FP entryptr, uint32_t arg);
int32_t bsakr_start_tsk(int32_t tskid, int32_t arg);
int32_t bsakr_terminate_tsk(int32_t tskid);
int32_t bsakr_delete_tsk(int32_t tskid);
void    exit_all_tsk(void);
#endif

#include "bsakr_task.h"

int32_t task_num = 0;
bool continue_program = true;
Thread_t *tk[MAX_TASK];

int32_t search_taskid(int32_t tskid) {
    int32_t ret_pos = -1;
    for (int i = 0; i < MAX_TASK; i++) {
        if ((tk[i] != NULL) && (tskid == tk[i]->id)) {
            ret_pos = i;
            break;
        }  
    }
    return ret_pos;
}

int32_t bsakr_create_tsk(int8_t *name, int32_t priority, int32_t stacksize, FP entryptr, uint32_t arg)
{
#ifdef _WIN32
    Thread_t *thrd = (Thread_t*)malloc(1*sizeof(Thread_t));
    int32_t id_thread, ret_api;

    ret_api = -1;

    if (task_num == MAX_TASK) {
        dump_message_dummy("There is no space to create task\n");
        return -1;
    }
    thrd->thread = NULL;

    thrd->thread = CreateThread(NULL, stacksize, (LPTHREAD_START_ROUTINE)entryptr, LPVOID(&arg), 0, (LPDWORD)&id_thread); 
    if (thrd->thread) {
        thrd->id = id_thread;
        tk[task_num] = thrd;
        task_num++;
        ret_api = id_thread;
    }
    else {
        dump_message_dummy("Cannot create thread\n");
        ret_api = -1;
    }
    return ret_api;
#endif
}

int32_t bsakr_start_tsk(int32_t tskid, int32_t arg) {
#ifdef _WIN32
    int32_t id_pos;
    HANDLE thread;
    
    id_pos = search_taskid(tskid); 
    if (id_pos == -1) {
        return E_ID;
    } 

    thread = tk[id_pos]->thread;
    if (ResumeThread(thread) == -1) {
        dump_message_dummy("Fail to launch task\n");    
        return E_SYS;
    }
    return E_OK;
#endif
}

int32_t bsakr_terminate_tsk(int32_t tskid) {
#ifdef _WIN32
    int32_t id_pos, exit_code, status;
    Thread_t *thrd;
    
    exit_code = STILL_ACTIVE;
    status = ERROR_INVALID_PARAMETER;
    id_pos = search_taskid(tskid); 
    if (id_pos == -1) {
        dump_message_dummy("Task id is not exist\n");
        return E_NOEXS;
    } 
    thrd = tk[id_pos];

    GetExitCodeThread(thrd->thread, (LPDWORD)&exit_code); 
    
    if (exit_code != STILL_ACTIVE) {
        dump_message_dummy("Task is not actived\n");
        return E_OBJ;
    }
    SuspendThread(thrd->thread);
    return E_OK;
#endif
}

int32_t bsakr_delete_tsk(int32_t tskid) {
    int32_t id_pos;
    Thread_t *thrd;
    DWORD exit_code;
    
    id_pos = search_taskid(tskid); 
    if (id_pos == -1) {
        return E_NOEXS;
    } 
    exit_code = STILL_ACTIVE;
    thrd = tk[id_pos];
    GetExitCodeThread(thrd->thread, &exit_code); 

    if (exit_code != STILL_ACTIVE) {
        return E_OBJ;
    }
    TerminateThread(thrd->thread, exit_code);
    CloseHandle(thrd->thread);
    thrd->thread = NULL;
    free(tk[id_pos]);
    task_num--;

    return E_OK;
} 

void exit_all_tsk(void) {
    DWORD exit_code;

    continue_program = false;
    for (int i = 0; i < MAX_TASK; i++) {
        if (tk[i] != NULL) {
            printf("i value is %d\n", i);
            //GetExitCodeThread(tk[i]->thread, &exit_code); 
            //if (exit_code != STILL_ACTIVE) {
            //    TerminateThread(tk[i]->thread, exit_code);
            //    CloseHandle(tk[i]->thread);
            //}
            do {
                GetExitCodeThread(tk[i]->thread, (LPDWORD)&exit_code);
                printf("Waiting to end driver\n");
            } while (exit_code == STILL_ACTIVE);
            //TerminateThread(tk[i]->thread, exit_code);
            //CloseHandle(tk[i]->thread);
            //tk[i]->thread = NULL;
            //free(tk[i]);
            Sleep(500);
        }      
    }
    for (int i = 0; i < MAX_TASK; i++) {
        if (tk[i] != NULL) {
            free(tk[i]);
        }
    }
}



