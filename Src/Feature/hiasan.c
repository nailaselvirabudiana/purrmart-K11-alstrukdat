#include "hiasan.h"


void opening() {
       printf(
       
        "                                                                          ;++++++++::;++++++++++;::;+++++++++++++++++++++++++++:                    \n"
        "                                                                          ;++++++;::+++++++++::;+++++++++++++++++++++++++++++++:                    \n"
        "                                                                          ;+++++;::+++++++;:;++++++;:::::::::::;+++++++++++++++:                    \n"
        "            +++:         +xxxx+.    .+xx.  :+xxxx;    .+xxxx+.            ;++++;:;++++++::++;:::...::::.....::++++;:.:;++++++++:                    \n"
        "           .+x;.         ;xxxx+.     +xx..+xxxxxxxx. +xxxxxxxx:           ;+++;::+++++:...:;XxxXX;:..............:++++++:::++++:                    \n"
        "          ..++xxxx++.    .+xxx+.     ;xx:.+x;.;+xxx:.+x+.:+xxx:           ;+++::++++;.....;$xXXXXX$$;:..............:++++++;::;:                    \n"
        "             .xx++xxx+.  .+xxxx;     +xx..+x+.:xxx+..+x+.:+xxx.           ;++::++++:.....;$xXXXXXXXXXXXX$xX$XXXX&$;......;+++++:                    \n"
        "              ;x+.  :+xx; ;xxxxx.   .xx+..+x+.:xxx+..+x+.:+xxx.           ;+;:;++;......:$xxXXXXXXXXXXXX$xX$XXXX&$;......:++++:                    \n"
        "              .+x+xxxx:    +xxxx+. .+xx; :xxxxxx+.  .+xxxxx+.             ;+::++:......:XXxXXXXXXXXXXXXXXXXXXXX$&&x:......:++++:                    \n"
        "              .+x+:.       .xxxxxx++xx+. :xxxxxxx:  .+xxxxxx;             ;;:;+:.......;$XX$$$$$$$$$$$&&$$$XXX$&&&X:......::;++:                    \n"
        "              .+x+           +xxxxxxxx;  :x;  :xxx: .++  .xxx;            ;;:+;:::.....+$X$$$$$$$$$$$$$$$$$$$&&&&&X:::::::::;:+:                    \n"
        "              .+x+.           .+xxxx+.   ;x;   .+xx::++    +xx;           ;::;::;;+x$&$$$$$XXX$$$$$$$$$$$$&&&&&$$$$$$$$$$:++:                    \n"
        "                                                                          ;::$$xxXXXXXXXXXXXXXXXXX$$$$$$$$$$$&&&&&$$$$$$$$$$:++:                    \n"
        "                                                                          ;:::::::;;;xXX$$XXXXXXXxx$+xxxxxXXX$$$XXX&&&$$$$X$:;+:                    \n"
        "                                                                          ;::::.....;+   XX.x$+X++x$X;:;$$.X$+xxxxx&&$$$$xx:::+:                    \n"
        "                                                                          ;::::::...:X.  .$$$;;x++++X.   ;x;.:Xxxxx$$Xx$+:::::+:                    \n"
        "                                                                          ;:::::::.....:+$$XX$X+:;+++++XX+;+$X+++xxx$;::.::::::;:                    \n"
        "                                                                          ;;:::::.....:Xx++++;:;;++++++++++++++xxx$:......:::::                    \n"
        "                                      :.                                  ;+:::.::;+++;;;;;;;;;;;;;;;;;++++++++xxxx$:......:::::                    \n"
        "               ;:                    :x+.      .;+xx+:  .+xxxxxxxxxxx;    ;+;:::+::;;;;;;;;;;;;;;;;;;;;;;;:++++xxxx$;......:::::                    \n"
        "              .++.     :.           .+++;     +xxxxxxx+..xxxxxxxxxxxx:    :++:::+++;;;;;;;;++++++++++++++;;;:++xxxx$;...::::::::                    \n"
        "              ;xx+     ++          .x+.:x:   .+x;:+xxxx.    ;xx:......    ;:;;::::::::::+Xx+++++;;;;;;;;+X$$x+xxxxxX;..:::::+:;:                    \n"
        "             .xxxx:   .+x+         +x:  ++.  .+x+ .+xx+.    ;xx;          ;+;::::.......;X+++++++++++xXx;++++Xxxxxxx;....::+;:+:                    \n"
        "             ;xxxxx:  .+xx;      .+x+.:;+x+. .xxxxxxxx;     :xx;          ;+++++++::::;X+X++++++++xx+x$$Xxxxxx$x+XxxxX;:+++::++:                    \n"
        "            :xx;:xx+. ;xxxx:     ;xx+;;+xxx; .xxxxxx+.      :xx+          ;+++++:....:::XX++++++++xX+++X++++xXXx$xx+X;:++:;+:                    \n"
        "           .+x+. ;xx+.+x;;x+.   :xx;    +xxx::xxxxxx+.      :xx+.         ;+++++++::::;X+xX++++++++xx+x$$Xxxxxx$x+XxxxX$++;:;+++:                    \n"
        "           :xx+. .+xx;xx. +xx. :xx+.    :xxx+;x+. :xxx:     :xx+.         :::+++++++;:X+xX++++++++++x+xXXXXXxxxx$xxxxX$++;:;+++:                    \n"
        "          .+xx:   .xxxx+  .+x+..;x:      :.  ;x+   :xxx:    .+x+.         ;++:::;++++xX+xX++++++++++x+xXXXXXxxxx$xxxxX$++;:;+++:                    \n"
        "                                                                          ;++++++;::;xx+xX++++++++++++++X$$$$$$xxxxxxX$x+:;++++:                    \n"
        "                                                                                                                                                   \n"
       
    );
}


void loading_animation(int duration){
    int i = 0;
    char spin[] = "|/-\\*+x"; 
    clock_t end_time = clock() + (clock_t)(duration * CLOCKS_PER_SEC);
    double total_ticks = duration * CLOCKS_PER_SEC;
    double elapsed_ticks = 0;

    while (clock() < end_time) {
        elapsed_ticks = clock() - (end_time - (clock_t)total_ticks);
        double progress = elapsed_ticks / total_ticks; 

        // Membuat progres bar
        int filled_length = (int)(progress * BAR_WIDTH);
        printf("\r["); // Mulai progres bar
        for (int j = 0; j < BAR_WIDTH; j++) {
            if (j < filled_length) {
                printf("#"); 
            } else {
                printf("-");
            }
        }
        printf("] %d%% %c", (int)(progress * 100), spin[i]); 

        fflush(stdout);
        i = (i + 1) % (sizeof(spin) - 1); 


        clock_t target = clock() + (clock_t)INTERVAL;
        while (clock() < target);
    }
    printf("\r[##############################] 100%% \n"); 
}


