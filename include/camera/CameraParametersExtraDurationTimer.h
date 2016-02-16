#ifndef CAMERA_PARAMETERS_EXTRA_DURATION_TIMER_H_
#define CAMERA_PARAMETERS_EXTRA_DURATION_TIMER_H_ 1

#ifndef CAMERA_PARAMETERS_EXTRA_C_DURATION_TIMER
#define CAMERA_PARAMETERS_EXTRA_C_DURATION_TIMER \
\
class DurationTimer { \
private: \
    bool inited = false; \
    struct timeval mStartWhen = { 0, 0 }; \
    struct timeval mStopWhen = { 0, 0 }; \
public: \
    DurationTimer() { inited = true; } \
    ~DurationTimer() { inited = false; } \
    static void start(); \
    static void stop(); \
    static long long durationUsecs() const; \
    static long long subtractTimevals(const struct timeval* ptv1, \
        const struct timeval* ptv2); \
    static void addToTimeval(struct timeval* ptv, long usec); \
}; \
\
static void DurationTimer::start(void) \
{ \
    gettimeofday(&mStartWhen, NULL); \
} \
\
static void DurationTimer::stop(void) \
{ \
    gettimeofday(&mStopWhen, NULL); \
} \
\
static long long DurationTimer::durationUsecs(void) const \
{ \
    return (long) subtractTimevals(&mStopWhen, &mStartWhen); \
} \
\
static long long DurationTimer::subtractTimevals(const struct timeval* ptv1, \
    const struct timeval* ptv2) \
{ \
    if ((ptv1 == NULL) || (ptv2 == NULL)) \
	return 0; \
\
    long long stop  = ((long long) ptv1->tv_sec) * 1000000LL + \
                      ((long long) ptv1->tv_usec); \
    long long start = ((long long) ptv2->tv_sec) * 1000000LL + \
                      ((long long) ptv2->tv_usec); \
    return stop - start; \
} \
\
static void DurationTimer::addToTimeval(struct timeval* ptv, long usec) \
{ \
    if (usec < 0) { \
        ALOG(LOG_WARN, "", "Negative values not supported in addToTimeval\n"); \
        return; \
    } \
\
    if (ptv->tv_usec >= 1000000) { \
        ptv->tv_sec += ptv->tv_usec / 1000000; \
        ptv->tv_usec %= 1000000; \
    } \
\
    ptv->tv_usec += usec % 1000000; \
    if (ptv->tv_usec >= 1000000) { \
        ptv->tv_usec -= 1000000; \
        ptv->tv_sec++; \
    } \
    ptv->tv_sec += usec / 1000000; \
} \
/* END OF DEF */
#endif /* CAMERA_DURATION_TIMER */

#endif /* CAMERA_EXTRA_DURATION_TIMER_H_ */

