

#if !defined(DLIB_EXPORT)
	#define DLIB_EXPORT /* NOTHING */

	#if defined(WIN32) || defined(WIN64)
		#undef DLIB_EXPORT
		#if defined(DLib_EXPORTS)
			#define DLIB_EXPORT __declspec(dllexport)
		#else
			#define DLIB_EXPORT __declspec(dllimport)
		#endif // defined(DLib_EXPORTS)
	#endif // defined(WIN32) || defined(WIN64)

	#if defined(__GNUC__) || defined(__APPLE__) || defined(LINUX)
		#if defined(DLib_EXPORTS)
			#undef DLIB_EXPORT
			#define DLIB_EXPORT __attribute__((visibility("default")))
		#endif // defined(DLib_EXPORTS)
	#endif // defined(__GNUC__) || defined(__APPLE__) || defined(LINUX)

#endif // !defined(DLIB_EXPORT)


