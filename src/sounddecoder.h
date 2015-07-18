#ifndef SOUNDDECODER_H
#define SOUNDDECODER_H

#ifdef __cplusplus
extern "C" {
#endif

typedef enum {
    SOUND_CHANNELS_MONO,
    SOUND_CHANNELS_STEREO,
    SOUND_CHANNELS_LEFT,
    SOUND_CHANNELS_RIGHT
} Sound_Channels;

typedef enum {
#ifdef HAVE_ALSA
    DRIVER_ALSA,
#endif
#ifdef HAVE_PULSEAUDIO
    DRIVER_PULSE,
#endif
#ifdef WIN32
    DRIVER_WINMM,
#endif
    DRIVER_FILE
} Sound_Driver;

extern char errorSoundDecoder[];

#ifndef WIN32
#ifdef HAVE_ALSA
int initSoundDecoder(const Sound_Channels _channels, const Sound_Driver _driver,const char *file, const char *_alsaDevice);
#else
int initSoundDecoder(const Sound_Channels _channels, const Sound_Driver _driver, const char *file);
#endif
#else
int initSoundDecoder(const Sound_Channels _channels, const Sound_Driver _driver, const char *file, unsigned int deviceId);
#endif
void runSoundDecoder(int *stop);
void freeSoundDecoder();

#ifdef __cplusplus
}
#endif
#endif // SOUNDDECODER_H
