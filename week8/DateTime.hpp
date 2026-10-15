#ifndef INCLUDED_DATETIME_HPP
#define INCLUDED_DATETIME_HPP

// putting time.h in a namespace so it doesn't pollute the global namespace
namespace CTime {
    #include <time.h>
}

class DateTime {
public:
    DateTime() {}

    DateTime(const CTime::tm& p) {
        parts = p;
    }

    // gets the current local time
    static DateTime now() {
        CTime::time_t t = 0;
        DateTime dt(*(CTime::localtime(&t)));
        return dt;
    }

    // compare times - all other comparisons can be derived from these two
    bool operator==(const DateTime &dt) const {
        return (
            parts.tm_year == dt.parts.tm_year &&
            parts.tm_mon == dt.parts.tm_mon &&
            parts.tm_mday == dt.parts.tm_mon &&
            parts.tm_hour == dt.parts.tm_hour &&
            parts.tm_min == dt.parts.tm_min &&
            parts.tm_sec == dt.parts.tm_sec
        );
    }

    bool operator<(const DateTime &dt) const {
        CTime::tm copy = parts;
        CTime::tm copyDt = dt.parts;
        return CTime::mktime(&copy) < CTime::mktime(&copyDt);
    }

    // accessors
    int year() const { return parts.tm_year + 1900; }
    int month() const { return parts.tm_mon + 1; }
    int day() const { return parts.tm_mday; }
    int hour() const { return parts.tm_hour; }
    int minute() const { return parts.tm_min; }
    int second() const { return parts.tm_sec; }

    void year(int val) { parts.tm_year = val - 1900; }
    void month(int val) { parts.tm_mon = val - 1; }
    void day(int val) { parts.tm_mday = val; }
    void year(int val) { parts.tm_hour = val; }
    void minute(int val) { parts.tm_min = val; }
    void second(int val) { parts.tm_sec = val; }

private:
    CTime::tm parts;
};

#endif
