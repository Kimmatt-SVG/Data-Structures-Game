document.addEventListener('DOMContentLoaded', () => {
    const hamburger = document.querySelector('.hamburger');
    const navMenu = document.querySelector('.nav-menu');
    const navLinks = document.querySelectorAll('.nav-link');
    const filterButtons = document.querySelectorAll('.filter-btn');
    const galleryItems = document.querySelectorAll('.gallery-item');
    const lightbox = document.getElementById('lightbox');
    const closeLightbox = document.querySelector('.close-lightbox');
    const lightboxPrev = document.querySelector('.lightbox-prev');
    const lightboxNext = document.querySelector('.lightbox-next');
    const contactForm = document.querySelector('.contact-form');

    let currentImageIndex = 0;
    let currentFilter = 'all';

    hamburger.addEventListener('click', () => {
        navMenu.classList.toggle('active');
        
        const spans = hamburger.querySelectorAll('span');
        if (navMenu.classList.contains('active')) {
            spans[0].style.transform = 'rotate(45deg) translate(5px, 5px)';
            spans[1].style.opacity = '0';
            spans[2].style.transform = 'rotate(-45deg) translate(7px, -6px)';
        } else {
            spans[0].style.transform = 'none';
            spans[1].style.opacity = '1';
            spans[2].style.transform = 'none';
        }
    });

    navLinks.forEach(link => {
        link.addEventListener('click', () => {
            navMenu.classList.remove('active');
            const spans = hamburger.querySelectorAll('span');
            spans[0].style.transform = 'none';
            spans[1].style.opacity = '1';
            spans[2].style.transform = 'none';
        });
    });

    filterButtons.forEach(button => {
        button.addEventListener('click', () => {
            filterButtons.forEach(btn => btn.classList.remove('active'));
            button.classList.add('active');
            
            const filterValue = button.getAttribute('data-filter');
            currentFilter = filterValue;
            
            galleryItems.forEach((item, index) => {
                const category = item.getAttribute('data-category');
                
                if (filterValue === 'all' || category === filterValue) {
                    item.style.display = 'block';
                    setTimeout(() => {
                        item.style.opacity = '1';
                        item.style.transform = 'scale(1)';
                    }, index * 50);
                } else {
                    item.style.opacity = '0';
                    item.style.transform = 'scale(0.8)';
                    setTimeout(() => {
                        item.style.display = 'none';
                    }, 300);
                }
            });
        });
    });

    galleryItems.forEach((item, index) => {
        item.addEventListener('click', () => {
            currentImageIndex = index;
            openLightbox();
        });
    });

    function openLightbox() {
        lightbox.classList.add('active');
        document.body.style.overflow = 'hidden';
        updateLightboxContent();
    }

    function closeLightboxFunc() {
        lightbox.classList.remove('active');
        document.body.style.overflow = 'auto';
    }

    function updateLightboxContent() {
        const visibleItems = Array.from(galleryItems).filter(item => {
            const category = item.getAttribute('data-category');
            return currentFilter === 'all' || category === currentFilter;
        });
        
        if (visibleItems.length > 0 && currentImageIndex < visibleItems.length) {
            const currentItem = visibleItems[currentImageIndex];
            const placeholder = currentItem.querySelector('.gallery-placeholder');
            const title = placeholder.querySelector('span').textContent;
            
            const lightboxContent = lightbox.querySelector('.lightbox-content');
            const lightboxPlaceholder = lightboxContent.querySelector('.lightbox-placeholder');
            
            const svg = placeholder.querySelector('svg').cloneNode(true);
            lightboxPlaceholder.innerHTML = '';
            lightboxPlaceholder.appendChild(svg);
            
            const titleSpan = document.createElement('span');
            titleSpan.textContent = title;
            titleSpan.style.position = 'absolute';
            titleSpan.style.bottom = '30px';
            titleSpan.style.left = '50%';
            titleSpan.style.transform = 'translateX(-50%)';
            titleSpan.style.fontSize = '1.5rem';
            titleSpan.style.fontWeight = '600';
            lightboxPlaceholder.appendChild(titleSpan);
        }
    }

    function showPrevImage() {
        const visibleItems = Array.from(galleryItems).filter(item => {
            const category = item.getAttribute('data-category');
            return currentFilter === 'all' || category === currentFilter;
        });
        
        currentImageIndex = (currentImageIndex - 1 + visibleItems.length) % visibleItems.length;
        updateLightboxContent();
    }

    function showNextImage() {
        const visibleItems = Array.from(galleryItems).filter(item => {
            const category = item.getAttribute('data-category');
            return currentFilter === 'all' || category === currentFilter;
        });
        
        currentImageIndex = (currentImageIndex + 1) % visibleItems.length;
        updateLightboxContent();
    }

    closeLightbox.addEventListener('click', closeLightboxFunc);
    
    lightbox.addEventListener('click', (e) => {
        if (e.target === lightbox) {
            closeLightboxFunc();
        }
    });

    lightboxPrev.addEventListener('click', (e) => {
        e.stopPropagation();
        showPrevImage();
    });

    lightboxNext.addEventListener('click', (e) => {
        e.stopPropagation();
        showNextImage();
    });

    document.addEventListener('keydown', (e) => {
        if (lightbox.classList.contains('active')) {
            if (e.key === 'Escape') {
                closeLightboxFunc();
            } else if (e.key === 'ArrowLeft') {
                showPrevImage();
            } else if (e.key === 'ArrowRight') {
                showNextImage();
            }
        }
    });

    contactForm.addEventListener('submit', (e) => {
        e.preventDefault();
        
        const formData = new FormData(contactForm);
        const name = e.target[0].value;
        const email = e.target[1].value;
        const message = e.target[2].value;
        
        alert(`Thank you for your message, ${name}! We'll get back to you at ${email} soon.`);
        contactForm.reset();
    });

    const observerOptions = {
        threshold: 0.1,
        rootMargin: '0px 0px -100px 0px'
    };

    const observer = new IntersectionObserver((entries) => {
        entries.forEach(entry => {
            if (entry.isIntersecting) {
                entry.target.style.opacity = '1';
                entry.target.style.transform = 'translateY(0)';
            }
        });
    }, observerOptions);

    document.querySelectorAll('.gallery-item, .about-content, .contact-content').forEach(el => {
        el.style.opacity = '0';
        el.style.transform = 'translateY(30px)';
        el.style.transition = 'opacity 0.6s ease, transform 0.6s ease';
        observer.observe(el);
    });

    window.addEventListener('scroll', () => {
        const navbar = document.querySelector('.navbar');
        if (window.scrollY > 50) {
            navbar.style.boxShadow = '0 4px 12px rgba(0, 0, 0, 0.15)';
        } else {
            navbar.style.boxShadow = '0 4px 6px rgba(0, 0, 0, 0.1)';
        }
    });

    const stats = document.querySelectorAll('.stat h3');
    let animated = false;

    function animateStats() {
        if (animated) return;
        
        stats.forEach(stat => {
            const target = parseInt(stat.textContent);
            let current = 0;
            const increment = target / 50;
            const timer = setInterval(() => {
                current += increment;
                if (current >= target) {
                    stat.textContent = target + '+';
                    clearInterval(timer);
                } else {
                    stat.textContent = Math.floor(current) + '+';
                }
            }, 30);
        });
        
        animated = true;
    }

    const aboutSection = document.querySelector('.about');
    const aboutObserver = new IntersectionObserver((entries) => {
        entries.forEach(entry => {
            if (entry.isIntersecting) {
                animateStats();
            }
        });
    }, { threshold: 0.5 });

    aboutObserver.observe(aboutSection);
});
