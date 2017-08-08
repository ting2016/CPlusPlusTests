def FlagsForFile( filename, **kwargs ):
    return {
        'flags': [
            '-x', 'c++',
            '-std=c++14',
            '-I/usr/include/c++/7.1.1'
        ]
    }
