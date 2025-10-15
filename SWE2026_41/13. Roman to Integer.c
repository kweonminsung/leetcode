int romanToInt(char* s) {
    int idx = 0, tot = 0, maxIdx = strlen(s) - 1;

    while(idx <= maxIdx && s[idx] == 'M') {
        tot += 1000;
        idx++;
    }
    if(maxIdx >= idx + 1 && s[idx + 1] == 'M') {
        tot += 900;
        idx += 2;
    }

    while(idx <= maxIdx && s[idx] == 'D') {
        tot += 500;
        idx++;
    }
    if(maxIdx >= idx + 1 && s[idx + 1] == 'D') {
        tot += 400;
        idx += 2;
    }

    while(idx <= maxIdx && s[idx] == 'C') {
        tot += 100;
        idx++;
    }
    if(maxIdx >= idx + 1 && s[idx + 1] == 'C') {
        tot += 90;
        idx += 2;
    }

    while(idx <= maxIdx && s[idx] == 'L') {
        tot += 50;
        idx++;
    }
    if(maxIdx >= idx + 1 && s[idx + 1] == 'L') {
        tot += 40;
        idx += 2;
    }

    while(idx <= maxIdx && s[idx] == 'X') {
        tot += 10;
        idx++;
    }
    if(maxIdx >= idx + 1 && s[idx + 1] == 'X') {
        tot += 9;
        idx += 2;
    }

    while(idx <= maxIdx && s[idx] == 'V') {
        tot += 5;
        idx++;
    }
    if(maxIdx >= idx + 1 && s[idx + 1] == 'V') {
        tot += 4;
        idx += 2;
    }

    while(idx <= maxIdx && s[idx] == 'I') {
        tot += 1;
        idx++;
    }
    return tot;
}